#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<ll>a(n);
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        sum+=a[i];
        a[i]*=2;
    }
    vector<ll>ans(n,0);
    ans[0]+=sum;
    for (int i = 0; i <n/2; ++i) {
        ans[0]-=a[1+i*2];
    }
    for (int i = 0; i < n - 1; ++i) {
//        cout <<a[i]<<" "<<ans[i]<<endl;
        ans[i+1]=a[i]-ans[i];
    }
    for (int i = 0; i < n; ++i) {
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    return 0;
}

