#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    double a,b,c,d; cin >> a >> b >> c >> d;
    int e = ceil(c/b), f = ceil(a/d);
    if(e <= f){
        cout << "Yes" << endl;
    }else cout << "No" << endl;
}