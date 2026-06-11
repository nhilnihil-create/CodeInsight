#include<bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
#define int long long

signed main(){
  int N;
  cin >> N;
  map<int,int> a;
  int A[200020];
  rep(i,N){
    cin >> A[i];
    a[A[i]]++;
  }
  int sum = 0;
  for(auto i : a){
    sum += i.second * (i.second-1) / 2;
  }
  rep(i,N){
    cout << sum - a[A[i]] + 1 << endl;
  }
}

