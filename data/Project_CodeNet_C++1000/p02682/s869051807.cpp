#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(k>a+b){
        cout << a-(k-a-b) << endl;
    } else if(k>a){
        cout << a << endl;
    } else {
        cout << k << endl;
    }
}