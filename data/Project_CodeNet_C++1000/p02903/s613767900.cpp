#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    rep(i,h){
        rep(j,w){
            if(i<b){
                if(j<a)printf("%c", '0');
                else printf("%c", '1');
            }else{
                if(j<a)printf("%c", '1');
                else printf("%c", '0');
            }
        }
        cout << endl;
    }
    return 0;
}