#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i,n){
        cin >> a.at(i);
        a.at(i)--;
    }
    rep(i,n){
        cin >> b.at(i);
    }
    rep(i,n-1){
        cin >> c.at(i);
    }

    int sum = 0;
    rep(i,n){
        sum += b.at(a.at(i));
        if(i > 0 && a.at(i) == a.at(i-1)+1){
            sum += c.at(a.at(i-1));
        }
    }
    cout << sum << endl;
}