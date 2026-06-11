#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b){
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a[0];
    int c = 0;
    while(a[0] % 2 == 0){
        a[0] /= 2;
        c++;
    }
    bool flag = true;
    for(int i=1; i<n; i++){
        cin >> a[i];
        if(a[i] % (1LL<<c) != 0 || (a[i] / (1LL<<c)) % 2 == 0){
            flag = false;
        }
        a[i] /= (1LL<<c);
    }

    if(!flag){
        cout << 0 << endl;
        return 0;
    }

    int lcm = a[0];
    for(int i=1; i<n; i++){
        lcm = lcm / gcd(lcm, a[i]) * a[i];
        if(lcm * (1LL<<(c-1)) > m){
            cout << 0 << endl;
            return 0;
        }
    }
    lcm *= (1LL<<(c-1));

    cout << (m+lcm)/lcm/2 << endl;

    return 0;
}