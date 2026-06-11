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
    vector<int> vec(n);
    rep(i,n){
        cin >> vec.at(i);
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j) continue;
            sum += vec.at(i)*vec.at(j); 
            //cout << sum << endl;
        }
    }
    cout << sum << endl;
}