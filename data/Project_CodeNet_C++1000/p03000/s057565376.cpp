#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int n,x;
    cin >> n >> x;
    vector<int> vec(n+1);
    rep(i,n) cin >> vec.at(i);
    vec.at(n) = 0;
    int boon = 0;
    int count = 0;
    for(int i=0;i<=n;i++){
        if(boon <= x) count++;
        boon += vec.at(i);
        //cout << boon << endl;
    }
    cout << count << endl;
}