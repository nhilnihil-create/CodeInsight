#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long A,V,B,W,T;
    cin >> A >> V >> B >> W >> T;
    if ( abs(B-A) <=  (V-W)*T) cout << "YES";
    else cout << "NO";
}