#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<iomanip>
using namespace std;

const double PI= acos(-1.0);

int gcd_func(int a, int b){
    return b? gcd_func(b, a%b) : a;
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,c,d,e; cin >> a>>b>>c>>d>>e;
    if(!a)
        cout << 1 << endl;
    else if(!b)
        cout << 2 << endl;
    else if(!c)
        cout << 3 << endl;
    else if(!d)
        cout << 4 << endl;
    else
        cout << 5 << endl;
    return 0;
}