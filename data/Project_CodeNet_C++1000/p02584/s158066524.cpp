#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    
    // Count amount of moves towards origin
    ll moves;
    moves = min(K, X/D);
    
    K -= moves;
    X -= moves*D;
    
    // How many moves are left? If odd amount, go one step further
    
    if(K%2 == 0){
        cout << X << "\n";
    }else{
        cout << D-X << "\n";
    }
}
