#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int x, y;
    cin >> x >> y;
    int turu,kame;
    turu = x * 2;
    kame = x * 4;
    if(y%2==1)
        cout << "No" << endl;
    else{
        if(y<=kame && y>=turu)cout<<"Yes"<<endl;
        else
            cout << "No" << endl;
    }
}