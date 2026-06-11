#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    int n, k;
    cin>>n>>k;
    ll tot=0;
    for(int i=k; i<=n+1; i++){
        ll m=(ll)(n+1-i)*i+1;
        tot+=m;
        tot=tot%1000000007;
    }
    cout << tot << endl;
    return 0;
}
