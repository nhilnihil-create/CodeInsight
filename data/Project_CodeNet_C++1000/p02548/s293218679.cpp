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
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int a = 1; i*a < n; a++){
                ans++;
            }
        }
        cout<<ans;
    }
}
