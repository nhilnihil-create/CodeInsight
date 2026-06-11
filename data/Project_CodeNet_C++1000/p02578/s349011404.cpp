#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 2*1e5+5;

ll a[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;
    for(int i = 0; i<n; i++) cin >>a[i];

    ll ans = 0;
    for(int i = 1; i<n; i++){
        if(a[i-1] > a[i]){
            ans += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }

    cout <<ans <<endl;

    return 0;
}
