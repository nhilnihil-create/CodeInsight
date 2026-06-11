#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ar array



int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, v;
    cin >> a >> v;
    int b, w;
    cin >> b >> w;
    int t;
    cin >> t;
    if(v > w && abs(a-b)<=abs(v-w)*t){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
