#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long long ull;
typedef long double ld;

int main(){

    ull a, b,c;
    cin >> a >> b >> c;
    ull d = c-a-b;
    if(d>0&&d*d>4*a*b)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}






