#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int keta(int a){
    int count = 0;
    while(a>0){
        a /=10;
        count++;
    }
    return count;
}


int main(void){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(keta(i)%2 == 1){
            ans++;
        } 
    }
    cout << ans << endl;
}