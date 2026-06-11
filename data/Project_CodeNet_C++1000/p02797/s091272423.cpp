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
    int n,k,s;cin >>n>>k>>s;
    int q=(s==2||s==1)?3:s-1;
    vector<int>a(n,q);
    for (int i = 0; i < k; ++i) {
        a[i]=s;
    }
    for (int i = 0; i < n; ++i) {
        cout <<a[i]<<endl;
    }
}
