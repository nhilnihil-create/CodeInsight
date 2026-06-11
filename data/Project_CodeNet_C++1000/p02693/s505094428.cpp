#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int k,a,b; cin >> k >> a >> b;
    int ok = 0;
    int v1 = (a/k)*k;
    if(v1>=a && v1<=b) ok = 1;
    v1 += k;
    if(v1>=a && v1<=b) ok = 1;
    cout << (ok ? "OK\n":"NG\n") ;
    return 0;
}