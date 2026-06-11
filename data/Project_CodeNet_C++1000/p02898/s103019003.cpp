#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int n,k;
    cin >> n >> k;
    int count = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a >= k) count++;
    }
    cout << count << endl;
}