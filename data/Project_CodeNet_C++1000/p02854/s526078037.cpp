#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    ll curl = 0;
    ll curr = accumulate(a.begin(), a.end(),0LL);
    ll nin =   curr - curl;

    for(int i = 0; i < n ;i++){
        curl +=a[i];
        curr -= a[i];
        nin = min(nin, abs(curl - curr));
        
    }
    cout << nin << endl;

}