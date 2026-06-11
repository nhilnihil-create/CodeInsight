#include <bits/stdc++.h>
using namespace std;
int const MX = 2e5 + 1, MOD = 1e9 + 7;
int a[MX], b[MX];
int main()
{
    int t = 1;
//    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool fl = false;
        for(int i = 0; i < n; i++) cin>>a[i]>>b[i];
        for(int i = 0; i < n - 2; i++){
            if(a[i] == b[i] && a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2]){
                fl = true;
                break;
            }
        }
        if(fl) cout<<"Yes";
        else cout<<"No";
    }
}
