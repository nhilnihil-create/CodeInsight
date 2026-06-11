#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    // a = 高橋のライフ　b = 高橋の攻撃力　c = 青木のライフ　d = 青木の攻撃力

    int i = 0;
    while(a > 0 && c > 0){
        c -= b;
        if(c <= 0){
            i = 1;
            break;
        }
        a -= d;
        if(a <= 0){
            break;
        }
    }
    if(i == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}