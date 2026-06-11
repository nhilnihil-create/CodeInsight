#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int h,w,a,b;
    cin >> h >> w >> b >> a;
    vector <vector <int>> s(h,vector <int>(w,0));

    rep(i,h-a){
        rep(j,b){
            s[i][j]=1;
        }
    }

    rep(i,a){
        rep(j,w-b){
            s[h-a+i][b+j]=1;
        }
    }

    rep(i,h){
        rep(j,w){
            cout << s[i][j];
        }
        cout << endl;
    }
    

    return 0;
}