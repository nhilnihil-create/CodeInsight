#include <bits/stdc++.h>
using namespace std;

vector<int> p;

void QS(int a,int b){
  if(b-a<=1){
    if(p.at(b)<p.at(a)){
      swap(p.at(b),p.at(a));
    }
    return;
  }
  int P=(p.at(a)+p.at(b))/2;
  int i=a,j=b;
  int X,Y;
  while(true){
    while(i<j){
      if(p.at(i)>P){
        break;
      }
      i++;
    }
    while(i<j){
      if(p.at(j)<=P){
        break;
      }
      j--;
    }
    if(i==j){
      X=j-1,Y=j;
    }
    else if(j-i==1){
      swap(p.at(i),p.at(j));
      X=i,Y=j;
    }
    else{
      swap(p.at(i),p.at(j));
      continue;
    }
    break;
  }
  if(X-a<=1){
    if(p.at(X)<p.at(a)){
      swap(p.at(X),p.at(a));
    }
  }
  else{
    QS(a,X);
  }
  if(b-Y<=1){
    if(p.at(b)<p.at(Y)){
      swap(p.at(b),p.at(Y));
    }
  }
  else{
    QS(Y,b);
  }
  return;
}

int main() {
  int N;
  cin>>N;
  p.resize(N);
  for (int i=0;i<N;i++){
    cin>>p.at(i);
  }
  QS(0,N-1);
  cout<<p.at(N/2)-p.at(N/2-1)<<endl;
}



