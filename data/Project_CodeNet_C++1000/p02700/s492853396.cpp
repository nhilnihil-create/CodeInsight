#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int a,b,c,d;
    bool win=false;
    cin >> a >> b >> c >> d;
    while(1){
        c -= b;
        if(c<= 0){
            win=true;
            break;
        }
        a -= d;
        if(a<=0) break;

    }
    if(win)cout << "Yes" << endl;
    else cout << "No" << endl;
}