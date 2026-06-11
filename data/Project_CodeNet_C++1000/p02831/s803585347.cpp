#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int x, int y){
    if(x%y==0) return y;
    else{
        return gcd(y, x%y);
    }
}

int main(){
    ll a,b;
    cin >> a >> b;
    cout << a*b/gcd(max(a,b), min(a,b)) << endl;
}