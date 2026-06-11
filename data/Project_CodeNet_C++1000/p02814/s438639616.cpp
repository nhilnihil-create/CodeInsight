#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long m; cin >> m;
    vector<long long> a(n);
    long long gcd;
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
        if(i == 0) gcd = a.at(i);
        else{
            gcd = __gcd(gcd, a.at(i));
        }
    }
    bool ok = true;
    int num = 0;
    while(a.at(0) % 2 == 0){
        a.at(0) /= 2;
        num++;
    }
    for(int i = 1; i < n; i++){
        int tmp = 0;
        while(a.at(i) % 2 == 0){
            a.at(i) /= 2;
            tmp++;
        }
        if(tmp != num){
            ok = false;
            break;
        }
    }
    if(ok){
        long long lcm = a.at(0);
        for(int i = 1; i < n; i++){
            lcm = lcm * a.at(i)/__gcd(lcm, a.at(i));
        }
        for (int i = 0; i < num - 1; i++){
            lcm *= 2;
        }
        long long ans = (m/lcm + 1)/2;
        cout << ans << endl;
    }
    else cout << 0 << endl;
}