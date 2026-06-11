#include<bits/stdc++.h>
using namespace std;

bool solve(int X, int Y){
    return ((Y-2*X)%2 == 0) && ((Y-2*X)/2 >= 0) && (X-(Y-2*X)/2 >= 0);
}

int main(){
    int X, Y;
    cin >> X >> Y;
    if(solve(X, Y)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}