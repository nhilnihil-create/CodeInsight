#include <bits/stdc++.h>
 using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; } template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } 
using ll=long long;
 int main(){
 int n;
   cin>>n;
   vector<int> d={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
   cout<<d[n-1]<<endl;
 }
