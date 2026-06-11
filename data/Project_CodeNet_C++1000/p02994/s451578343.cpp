#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int n,l;
    cin >> n >> l;
    vector<int> azi(n);
    int hoge = 999;
    int hoge2 = 0;
    for(int i=0;i<n;i++){
        azi.at(i) = l+i+1-1;
        if(hoge > abs(azi.at(i))){
            hoge = abs(azi.at(i));
            hoge2 = azi.at(i);
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += azi.at(i);
    }
    cout << sum-hoge2 << endl;
}