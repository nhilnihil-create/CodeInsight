#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    int n; cin >> n;
    if(n%2==1){
        int o = n/2 + 1;
        int e = n/2;
        cout << setprecision(10) << 1.0*o/n << endl;
    }else{
        cout << 0.5 << endl;
    }
}