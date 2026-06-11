#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,m; cin >> n >> m;
    long long ac, a[n], num=0, x; cin >> a[0];
    a[0]/=2;
    x = a[0];
    while(x % 2 == 0){
        x /= 2;
        num++;
    }
    bool ok = true;
    for (int i=1; i<n; i++){
        cin >> a[i];
        a[i] /= 2ll;
        x = a[i];
        int temp=0;
        while(x % 2 == 0){
            temp++;
            x/=2;
        }
        if (temp != num) ok =false;
    }
    if (!ok){
        cout << "0\n";
        return 0;
    }
    ac = a[0];
    for (int i=1; i<n; i++){
        ac = ac*a[i]/__gcd(ac, a[i]);
        if (ac > 2*m){
            ok = false;
            break;
        }
    }
    if (!ok) cout << "0\n";
    else cout << m/ac - m/(ac*2) << endl;
}