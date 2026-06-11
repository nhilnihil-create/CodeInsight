#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(0ll,b+c-a);
}