#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long A,B,V,W,T;
    cin >> A >> V >> B >> W >> T;
    if(W >= V) cout << "NO" << endl;
    else if(A < B){
        if(B + W*T > A + V*T) cout << "NO" << endl;
        else cout << "YES" << endl;
    } 
    else{
        if(B - W*T < A - V*T) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
