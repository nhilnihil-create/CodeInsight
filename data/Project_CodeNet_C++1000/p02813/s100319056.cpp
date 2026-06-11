#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int p[n],q[n];
    rep(i,n)cin >> p[i];
    rep(i,n)cin >> q[i];
    vector<int>m(n);
    rep(i,n)m[i] = i+1;
    int a = 0,b = 0;
    int cnt = 1;
    do{
        bool okp = true,okq = true;
        rep(i,n)if(m[i]!=p[i])okp = false;
        rep(i,n)if(m[i]!=q[i])okq = false;
        if(okp)a = cnt;
        if(okq)b = cnt;
        cnt++;
    }while(next_permutation(all(m)));
    cout << abs(a-b) << endl;
    return 0;
}