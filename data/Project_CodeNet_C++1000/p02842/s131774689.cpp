#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    bool flag=false;
    rep(i,50000){
        if(i*108/100==n){
            flag=true;
            cout << i << endl;
            break;
        }
    }
    if(flag==false) cout << ":(" << endl;

}
