#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* */

int main(){
    // 入力スタンダード
    ll a, b, c;
    cin >> a >> b >> c;

    if(c-a-b >0){
        if( 4*a*b < (c-a-b)*(c-a-b)){
            cout << "Yes" <<endl;
            return 0;
        }
    }
    cout << "No" <<endl;
    return 0;
}