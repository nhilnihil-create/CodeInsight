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
    int n;
    string s;
    cin >> n >> s;

    int ans(0);
    rep(i,n-2){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') ans++;
    }

    cout << ans << endl;

    return 0;
}