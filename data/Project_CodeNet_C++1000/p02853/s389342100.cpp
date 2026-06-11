#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, Y;
    cin >> X >> Y;
    cout << (max(0, 4-X) + max(0, 4-Y) + max(0, 2-X*Y)*4)*100000 << endl;
}