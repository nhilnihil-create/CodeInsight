#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a==b){
        if(b!=c){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(b==c){
        if(c!=a){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(a==c){
        if(c!=b){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}