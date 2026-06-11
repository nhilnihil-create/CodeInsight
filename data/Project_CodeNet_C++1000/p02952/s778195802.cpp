#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

bool is_odd_digits(int n){
    int d = 0;
    while(n>0){
        n /= 10;
        d++;
    }
    return d % 2 == 1 ? true : false;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(is_odd_digits(i))ans++;
    }
    cout << ans << endl; 
}