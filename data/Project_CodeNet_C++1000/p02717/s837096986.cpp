#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; // int -> ll
#include <utility> // C++11から

int main(){
    ll x,y,z,t;
    cin >> x>>y>>z;
    t=x;
    x=y;
    y=t;

    t=x;
    x=z;
    z=t;
    cout << x <<" "<< y << " " << z << endl;


}
