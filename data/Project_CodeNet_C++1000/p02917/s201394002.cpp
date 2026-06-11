#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)
#define INF (1LL << 60)

int main(void){
    int n;
    cin >> n;
    int b[n-1];rep(i,n-1)cin >> b[i];
    
    vector<int> a(n,0);
    ll sum = 0;
    a[0] = a[1] = b[0];
    for(int i = 1;i < n-1;i++){
        a[i+1] = b[i];
        if(a[i] > a[i+1])a[i] = a[i+1];
    }
    rep(i,n)sum += a[i];
    
    cout << sum << endl;
}