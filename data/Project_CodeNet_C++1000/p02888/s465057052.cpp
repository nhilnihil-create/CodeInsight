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
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
   int n;cin >>n;
   V l(n);
    for (int i = 0; i < n; ++i) {
        cin >>l[i];
    }
    sort(all(l));
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j =i+1; j < n; ++j) {
            int sum=l[i]+l[j];
            int key=lower_bound(all(l),sum)-l.begin();
            if(key==n)key--;
            if(l[key]>=sum)key--;
            ans+=key-j;
        }
    }
    cout <<ans <<endl;
}
