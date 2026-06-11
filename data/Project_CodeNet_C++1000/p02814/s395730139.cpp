#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    long long lcm = 1;
    vector<long long>v(n + 3);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(v[i] != 4 && v[i] != 68){
        }
    }
    long long g = v[1];
    for(int i = 1; i <= n; i++){
        g = __gcd(g, v[i]);
        lcm = (v[i]/__gcd(lcm, v[i])) * lcm;
        if(lcm > 2 * m){
            cout << '0';
            return 0;
        }
    }
    if((lcm/g) % 2 == 0){
        cout << '0';
        return 0;
    }
    long long x = (2 * m)/lcm;
    cout << x/2 + (x % 2 != 0);
    return 0;
}