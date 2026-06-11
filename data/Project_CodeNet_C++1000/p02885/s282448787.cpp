#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    int a,b; cin >> a >> b;
    b *= 2;
    if(b>=a){
        cout << 0 << endl;
    }else{
        cout << a - b << endl;
    }
}