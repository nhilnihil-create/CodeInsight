#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main() {
    int n,m;
    cin >> n>>m;
    if(n%2==1){
        rep(i,m){
            int a = n/2;
            cout << (a-i) << " " << n-(a-i) << endl;
        }
    }else{
        int a = n/2;
        if(m<=n/4){
            rep(i,m){
                cout << (a-i) << " " << n+1-(a-i) << endl;
            }
        }else{
            rep(i,n/4){
                cout << (a-i) << " " << n+1-(a-i) << endl;
            }
            rep(j,m-n/4){
                cout << (j+1) << " " << n-(j+1) << endl;
            }
        }
    }
}