#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;
 
vector<ll> divisor(ll a){
    vector<ll> res;
    for(ll i=2; i<=sqrt(a); i++){
        if(a%i==0){
            res.push_back(i);
            if(i!=a/i) res.push_back(a/i);
        }
    }
    res.push_back(a);
    sort(all(res));
    return res;
}


int main(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    int sum=0;
    rep(i,n){
        cin >> a[i];
        sum+=a[i];
    }

    vector<ll> p=divisor(sum);
    reverse(all(p));

    rep(i,p.size()){
        vector<ll> moda;
        rep(j,n){
            if(a[j]%p[i]) moda.push_back(a[j]%p[i]);
        }
        int ms=moda.size();
        if(!ms){
            cout << p[i] << endl;
            return 0;
        }
        sort(all(moda));
        vector<ll> rmoda(ms+1);
        rmoda[0]=0;
        rep(j,ms) rmoda[j+1]=p[i]-moda[j]+rmoda[j];
        ll now=0;
        rep(j,ms){
            now+=moda[j];
            if(now==rmoda[ms]-rmoda[j+1]){
                if(now<=k){
                    cout << p[i] << endl;
                    return 0;
                }
                break;
            }
            else if(now>rmoda[ms]-rmoda[j+1]) break;
        }
    }
    cout << 1 << endl;
return 0;
}
