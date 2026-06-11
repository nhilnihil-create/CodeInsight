#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()   {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll available = 1000;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n-1; i++){
        ll s = 0;
        s = available/a[i];
        if(a[i] < a[i+1])  available+=(a[i + 1] - a[i])*s;


    }
    cout << available  << "\n";
    return 0;
}
