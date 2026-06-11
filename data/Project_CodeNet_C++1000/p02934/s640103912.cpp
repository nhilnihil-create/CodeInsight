#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i,n) cin >> a[i];
   double sum=0;
   rep(i,n) sum += 1.0/a[i];
   sum = 1/sum;
   cout <<fixed<< sum << endl;
   return 0;
}