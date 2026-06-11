#include <bits/stdc++.h>


using namespace std;
using ll = long long;
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
#define rep(i,n) for(int i = 0;i<n;i++)



int main(){

    int N;cin >> N;
    ll r = 0;
    vector<int> a(N-1);
    vector<int> b(N-1);
    int x,y;
    rep(i,N-1){
        cin >> x >> y;
        a[i] = min(x,y);
        b[i] = max(x,y);
    }
    rep(i,N)r += ll(i+1)*(N-i);

    rep(i,N-1){
        

        r -= ll (a[i])*(N-b[i]+1);
    }
    cout << r << endl;
    

}

