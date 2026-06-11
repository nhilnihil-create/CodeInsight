#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll H,W,A,B;
    cin >> H >> W >> A >> B;
    rep(i,B){
        rep(j,A){
            cout << "1";
        }
        rep(j,W-A){
            cout << "0";
        }
        cout << endl;
    }
    rep(i,H-B){
        rep(j,A){
            cout << "0";
        }
        rep(j,W-A){
            cout << "1";
        }
        cout << endl;
    }
    /*
    ll n = -1, m = -1;
    bool flag = false;
    rep(i,H+1){
        rep(j,W+1){
            if(i*A +(H-i)*(W-A) == j*B + (W-j)*(H-B)){
                n = i;
                m = j;
                flag = true;
                break;
            }
        }
        if(flag)break;
    }
    if(!flag){
        cout << "No"<<endl;
        return 0;
    }
    rep(i,n){
        rep(j,i){
            cout << '1';
        }
        rep(j,A){
            cout << '0';
        }
        rep(j,W-A-i){
            cout << '1';
        }
        cout << endl;
    }
    rep(i,H-n){
        rep(j,i){
            cout << '0';
        }
        rep(j,A){
            cout << '1';
        }
        rep(j,W-A-i){
            cout << '0';
        }
        cout << endl;
    }
    */
}
