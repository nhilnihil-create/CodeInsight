#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    ll N,K;
    ll n,k,len,cp;
    cin >> N >> K;

    vi A(N);
    vi r;
    vi odr(N+1,-1);
    rep(i,N) cin >> A[i];

    n = 1;
    while(odr[n] == -1){
        odr[n] = r.size();
        r.push_back(n);
        n = A[n-1];
    }

    cp = odr[n];
    len = r.size() - cp;
    if(K >= cp){
        K -= cp;
        k = (K % len) + cp;
    }else{
        k = K;
    }
    cout << r[k] << endl;

    return 0;
}