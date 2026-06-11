#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    ll S, x1,x2,x3,y1,y2,y3;
    cin >> S;
    if(S%(ll(1e9)) == 0){
        y3 = S/1e9;
        x3 = 0;
    }else{
        ll r = S % (ll(1e9));
        x3 = 1e9 - r;
        y3 = (S+x3) / ll(1e9);
    }

    cout << "0 0 1000000000 1 "<< x3 <<" "<<y3<<endl;
    /*
    ll L = 0;
    ll R = S+1;
    while(L + 1 < R){
        ll X = (L+R)/2;
        if(X > 1e10){
            L = X;
        }else{
            if(S/X > 1e10){
                R 
            }
        }
    }
    */    
}
