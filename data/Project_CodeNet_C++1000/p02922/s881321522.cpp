//Power Socket

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(ll i=x;i<y;i++)

int main(){
    double a, b;
    cin >> a >> b;
    b -= 1;
    cout << ceil(b / (a - 1)) << endl;
}