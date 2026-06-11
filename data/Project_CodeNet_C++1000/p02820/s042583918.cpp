#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int R,S,P;

int Point(char x){
  if(x=='r'){
    return P;
  }
  if(x=='s'){
    return R;
  }
  if(x=='p'){
    return S;
  }
}

int main(){
  int N,K;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  int ans=0;
  for(int i=0;i<K;i++){
    int count=1;
    char current=T[i];
    for(int j=1;j<=N/K+1;j++){
      if(K*j+i>=N){
        ans=ans+(count+count%2)/2*Point(current);
        break;
      }
      if(T[K*j+i]==current){
        count++;
      }
      else{
        ans=ans+(count+count%2)/2*Point(current);
        current=T[K*j+i];
        count=1;
      }
    }
  }
  cout << ans << endl;
}