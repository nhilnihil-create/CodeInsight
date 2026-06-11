#include "bits/stdc++.h"

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lin "\n"
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(0)

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n&1){
        cout<<"No";
        return;
    } else{
        for(int i=0;i<n/2;++i){
            if(s[i]!=s[i+n/2]){
                cout<<"No";
                return;
            }
        }
    }
    cout<<"Yes";
}

int main() {
    fast_io;
    int t = 1;
//    cin >> t;
    int c = 1;
    while (t--) {
//        printf("Case %lld: ",c);
//        cout<<"Case "<<c<<": ";
        solve();
        c++;
    }
}