#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};


ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t=rep_jijo(n,x/2);
        return t*t%mod;
    }
    return n*rep_jijo(n,x-1)%mod;
}


int main(){
    int n;
    const int A = 1000005;
    cin >> n;
    vector<int>a(A,0);
    vector<int>b(n);
    rep(i,n){
        int x;
        cin >> x;
        b[i] = x;
        a[x]++;
    }

    bool flag = true;

    for(int i = 2; i < A; i++){
        int cnt = 0;

        for(int j = i; j < A; j+=i){
            cnt += a[j];
            if(cnt > 1){
                flag = false;
            }
        }
    }


    if(flag){
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int x = 0;
    rep(i,n){
        x = gcd(x,b[i]);
    }

    if(x == 1){
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;


    return 0;
}
