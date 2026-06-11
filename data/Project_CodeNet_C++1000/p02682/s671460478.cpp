#include <bits/stdc++.h>
using namespace std;

long long A, B , C , K ;

void input() {
    cin >> A >> B >> C >> K ;
}

int main() {
    input() ;
    
    if( A >= K ){
        cout << K << endl;
    }
    
    else if( A+B >= K ){
        cout << A << endl;
    }
    
    else{
        cout << 2*A + B - K << endl;
    }
    
}
