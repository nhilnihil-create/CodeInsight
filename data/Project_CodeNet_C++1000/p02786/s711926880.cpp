#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    ll func(ll h){
        if(h==1){
            return 1;
        }
        return 2*func(h/2)+1;
    }


int main(){
    ll h;
    cin >> h;

    if(h==1){
        cout << 1 << endl;
      //  cout << "manji" << endl;
    }
    else{
        cout << func(h) << endl;
    
    }

    return 0;
}