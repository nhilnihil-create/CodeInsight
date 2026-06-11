#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    int t=1;
    //cin >> t;
    while(t--){
        ll a,b,k;
        cin >> a >> b >> k;
        cout << max((ll)0,a-k) << " " << max((ll)0,b-max((ll)0,k-a));
    }
}