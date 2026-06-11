#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int N,K,Q;
  cin >> N >> K >>Q;
  vector<int>A(N); //N人目のtokuten
  rep(i,N){
    A[i] = K;
  }
  int x;
  rep(i,Q){
    cin >> x;
    A[x-1]++;
  }
  rep(i,N){
    A[i] -= Q;
    if(A[i] <= 0)cout << "No" << endl;
    else cout << "Yes" << endl;
  } 
}