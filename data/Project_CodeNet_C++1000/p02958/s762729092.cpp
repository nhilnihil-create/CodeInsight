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
    int p[n];
    int swap = 0;
    int flag = false;
    for(int i=1;i<n;i++) cin >> p[i];
    int a = 0;
    for(int i=1;i<n;i++){
        if(i != p[i]) a++;
    }
    if(a <= 2){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}