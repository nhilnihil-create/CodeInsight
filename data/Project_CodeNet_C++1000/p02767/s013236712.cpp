#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;



int main(){
   int n; cin>>n;
   vector<int> a(n);
   rep(i, n) cin>>a[i];
   sort(a.begin(), a.end());
   ll ans = MOD;
   for(int i = a[0]; i <= a[n - 1]; i++){
       ll now = 0;
       rep(j, n) now += (a[j] - i) * (a[j] - i);
       ans = min(ans, now);
   }
   cout<< ans <<endl;
}
