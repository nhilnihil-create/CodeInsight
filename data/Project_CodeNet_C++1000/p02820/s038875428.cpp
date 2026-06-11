#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,K;cin >> N >> K;
  int R,S,P;cin >> R >> S >> P;
  string T;cin >> T;
  int sum = 0;
  for(int i=0;i<K;i++){
    vector<char> X;
    for(int j=0;i+K*j<N;j++){
      X.push_back(T[i+K*j]);
    }
    int M = X.size();
    int k=0;
    for(int j=0;j<M;j++){
      if(j==M-1){
        int y = (j-k)/2+1;
        if(X[j]=='r'){
          sum += y*P;
        }else if(X[j]=='s'){
          sum += y*R;
        }else{
          sum += y*S;
        }
        //cout << i << " " << j << " " << k << " " << T[i] << endl;
        break;
      }
      if(X[j]!=X[j+1]){
        int y = (j-k)/2+1;
        if(X[j]=='r'){
          sum += y*P;
        }else if(X[j]=='s'){
          sum += y*R;
        }else{
          sum += y*S;
        }
        //cout << i << " " << j << " " << k << " " << T[i] << endl;
        k = j + 1;
      }
    }
  }
  cout << sum << endl;
}