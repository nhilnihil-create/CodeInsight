#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll h,w,a,b; cin >> h >> w >> a >>b;

    rep(i,h){
        if(i<b){
            rep(j,w){
                if(j<a){
                    cout << 0;
                }else{
                    cout << 1;
                }
            }
        }else{
            rep(j,w){
                if(j<a){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }
        }
        cout << endl;
    }
}