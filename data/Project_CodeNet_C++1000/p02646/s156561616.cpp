#include <bits/stdc++.h>
using namespace std;
int main(){
    long long A, B, V, W, T;
    cin >> A >> V;
    cin >> B >> W;
    cin >> T;
    if (A <= B){
        if (T*V + A >= T*W + B) cout << "YES" << endl;
        else cout << "NO" << endl;
    }else{
        if (B - W*T >= A - V*T) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}