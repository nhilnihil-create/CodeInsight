#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}

int main(){
    int n,m;
    ll sum=0;
    cin >> n >> m;
    vector<double> a(n);
    rep(i,n){
        cin >> a[i];
        sum+=a[i];
    }
    double count=(double)sum/(4*m);
    //cout << count << endl;
    sort(a.begin(),a.end(),greater<double>());
    rep(i,m){
        if(a[i]<count){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}