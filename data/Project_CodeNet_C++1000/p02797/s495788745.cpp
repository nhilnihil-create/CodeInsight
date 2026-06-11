#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
   int n,k,s;cin >>n>>k>>s;
   int now;
   if(s==1||s==2){
       now=3;
   }
   else {
       now=s-1;
   }
   vector<int>ans(n,now);
    for (int i = 0; i < k; ++i) {
        ans[i]=s;
    }
    for (int i = 0; i < n; ++i) {
        cout <<ans[i]<<" ";
    }
    cout <<endl;
}
