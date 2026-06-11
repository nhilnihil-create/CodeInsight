#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   ll n,m;cin >>n>>m;
   m--;
   vector<int>a(n);
   ll sum=0;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        sum+=a[i];
    }
    sort(all(a));
    reverse(all(a));
    if(a[m]*4*(m+1)>=sum)puts("Yes");
    else puts("No");
}
