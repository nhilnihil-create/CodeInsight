#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  int i;
  for(i=0;i<n;i++){
    cin >> h.at(i);
  }
  
  int c,m;
  c=0,m=0;
  for(i=0;i<n-1;i++){
    if(h.at(i)>=h.at(i+1)){
      c++;
    }else{
      m=max(m,c);
      c=0;
    }
  }
  m=max(m,c);
  cout << m << endl;
}