#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int main() {
    ll a , b , c;
    cin >> a >> b >> c;
    ll d = c - a - b;
    if(d > 0 && d * d > 4 * a * b){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}