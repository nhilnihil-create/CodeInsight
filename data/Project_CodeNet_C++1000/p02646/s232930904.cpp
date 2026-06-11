#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int a,v,b,w,t;
    cin >> a >> v >> b >> w >> t;

    int s, d;
    d = abs(a - b);
    s = abs(w - v);

    if(w >= v) cout << "NO" << endl;
    else if(d <= (long long)s * t) cout << "YES" << endl;
    else cout << "NO" << endl;
}

