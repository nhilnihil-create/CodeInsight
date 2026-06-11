#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    long double a,b,c;
    cin >> a >> b >> c;

    long double ra = sqrt(a) , rb = sqrt(b) , rc = sqrt(c);
    long double e = 0.00000000000001;

    if((ra + rb + e) < rc){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}
