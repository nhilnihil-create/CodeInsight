#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const ll mod = 1e9 + 7;
int main(){
    ll W, H;
    cin >> W >> H;
    ll x, y;
    cin >> x >> y;
    if(W%2 == 0 && W/2 == x && H%2 == 0 && H/2 == y){
        cout << W*H/2 << ".000000000" << " " << "1" << endl;
        return 0;
    }

    if(W%2 == 1 && H%2 == 1){
        cout << W*H/2 << ".500000000" << " " << "0" << endl;
    }else{
        cout << W*H/2 << ".000000000" << " " << "0" << endl;
    }
}