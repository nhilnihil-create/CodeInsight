#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int x = i * 108/100;
        if(x == n){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<":("<<endl;
}