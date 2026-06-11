#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    if(t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2){
        cout << "infinity" << endl;
        return 0;
    }

    if(t1 * a1 + t2 * a2 < t1 * b1 + t2 * b2){
        swap(a1, b1);
        swap(a2, b2);
    }

    if(a1 > b1){
        cout << 0 << endl;
        return 0;
    }

    long long int dist1 = (b1 - a1) * t1;// > 0
    long long int dist2 = (t1 * a1 + t2 * a2) - (t1 * b1 + t2 * b2);// > 0

    long long int k = dist1 / dist2;
    long long int ans = k + (k - max(0LL, (dist1 - (a2 - b2) * t2) / dist2)) + 1;
    if(dist1 % dist2 == 0) ans -= 1;
    cout << ans << endl;
    return 0;
}