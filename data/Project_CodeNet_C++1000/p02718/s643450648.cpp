#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    int m, n;
    cin>>n>>m;
    vector<int> a(n);
    rep(i, n) cin>>a[i];

    int sum=0;
    rep(i, n) sum+=a[i];
    sort(a.rbegin(), a.rend());
    bool ok=true;
    rep(i, m) if(a[i]*4*m < sum) ok=false;

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
