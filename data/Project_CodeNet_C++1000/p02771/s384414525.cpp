#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll x, y, z;
    cin >> x >> y >> z;
    if(x == y && x == z || y == x && y == z || z == x && z == y || x != y && x != z && y != z)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
