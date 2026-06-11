#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> p(n), q(n);
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> q[i];
    ll a, b;
    int array[]={1,2,3,4,5,6,7,8};
    ll itr = 0;
    do{
        itr++;
        bool pf = true, qf = true;
        for(int i=0; i<n; i++){
            if(array[i] != p[i]) pf = false;
            if(array[i] != q[i]) qf = false;
        }
        if(pf) a = itr;
        if(qf) b = itr; 
    }while(next_permutation(array,array+n));
    cout << abs(a-b) << endl;
    return 0;
}