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
    int ans=0;
    int n;cin >>n;
    vector<int>a(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >>a[i];
    }
    ans+=a[0];
    ans+=a[n-2];
    for (int j = 0; j < n -2; ++j) {
        ans+=min(a[j],a[j+1]);
    }
    cout <<ans <<endl;
    return 0;
}