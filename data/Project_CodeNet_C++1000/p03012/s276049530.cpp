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
    int w[n];
    rep(i,n) cin >> w[i];
    int sum1 = 0;
    int sum2 = 0;
    int ans = 0 , value = 10000;
    for(int i=0;i<n;i++){
        sum1 += w[i];
        sum2 = 0;
        for(int j=i+1;j<n;j++){
            sum2 += w[j];
        }
        ans = abs(sum2-sum1);
        if(ans < value){
            value = ans;
        }
    }
    cout << value << endl;
}