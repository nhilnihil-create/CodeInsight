#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    ll a,b,k;
    cin >> a >> b >> k;
    if(k <= a){
        cout << a-k << " " << b << endl;
    }else if(k <= a+b){
        cout << 0 << " " <<  b-(k-a) << endl;;
    }else{
        cout << 0 << " " << 0 <<endl;
    }
}