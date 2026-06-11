#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    double p1 = (double)a/(double)d;
    double p2 = (double)c/(double)b;
    int p11 = ceil(p1);
    int p22 = ceil(p2);
    if(p11 >= p22)cout << "Yes"<<endl;
    else cout << "No" <<endl;
}
