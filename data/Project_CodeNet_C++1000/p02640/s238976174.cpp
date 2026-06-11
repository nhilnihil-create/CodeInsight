#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int  main(){
    int x,y,flag=0;
    cin >> x >> y;
    rep(i,x+1){
        if(i*2+(x-i)*4==y) flag = 1;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
