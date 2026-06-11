#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

double kaijyo(int n){
    int k(1);
    for(int i=n;i>0;i--){
        k *= i;
    }

    return k;
}

double distance(int x[],int y[],int i,int j){
    int dx = (x[i] - x[j]) * (x[i] - x[j]);
    int dy = (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(dx+dy);
}

int main(){
    ll n,k;
    cin >> n >> k;

    if(n%k==0)    
        cout << n/k << endl;
    else
        cout << n/k+1 << endl;

    return 0;
}