#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    ll p = 2;
    for(int i = 2; i < n; i++){
        v[i] *= p;
        p *= 2;
    }
    ll s = 0;
    for(int i = 0; i < n; i++)
        s += v[i];
    double ans = (double)s / p;
    printf("%.8f\n",ans);
    return 0;
}