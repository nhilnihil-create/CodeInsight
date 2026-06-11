#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll x; cin >> x;

    ll p = 100;
    int years = 0;
    while(p<x){
        p += p/100;
        years++;
    }
    cout << years << endl;
}
