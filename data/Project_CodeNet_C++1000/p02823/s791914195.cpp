#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    ll N,A,B; cin >> N >> A >> B;
    ll l = B-A-1;
    ll res = 0;
    if(l%2){
        res = l/2+1;
    }else
    {
        res = min(A-1,N-B) + (B-A-1)/2 + 1;
    }
    cout << res << endl;
}