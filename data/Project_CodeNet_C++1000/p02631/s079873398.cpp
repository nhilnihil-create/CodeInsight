/*
* @Author: dnhirapara
* @Problem: abc171_e
* @Time: 07-September-2020 : ( 16:20:25 )
*/
#include <bits/stdc++.h>

using namespace std;

/************defination************/

#define endl "\n"
#define logger(x) cout << __LINE__ << ": " << #x << " -> " << (x) << endl;
#define ll long long int
#define ull unsigned long long int

//@time comp :
//@space comp :
int main()
{
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // cin.ignore(); must be there when using getline(cin, s)
    ll tc = 1;
    //cin >> tc;
    while (tc--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll ans[n];
        ll cumulative_xor = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            cumulative_xor ^= a[i];
        }
        for (int i = 0; i < n;i++){
            ans[i] = cumulative_xor ^ a[i];
            cout << ans[i] << " ";
        }

    }
    return 0;
}