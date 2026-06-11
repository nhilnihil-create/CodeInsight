#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; // int -> ll
#include <utility> // C++11から

int main(){
    ll x,y,z,t;
    cin >> x>>y>>z;
  	std::swap(x,y);
  	std::swap(x,z);
    cout << x <<" "<< y << " " << z << endl;


}
