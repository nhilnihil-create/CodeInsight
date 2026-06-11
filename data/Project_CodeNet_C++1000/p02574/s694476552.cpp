#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll gcd(ll a,ll b){
  if(!b) return a;
  return gcd(b,a%b);
}
vec Era(int n){
    vec is_prime(n+1,0),Q;
    for(int i=2;i<=n;i++){
        if(!is_prime[i]){
            for(int j=i;j<=n;j+=i) is_prime[j]=i;
            Q.push_back(i);
        }
    }
    return is_prime;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vec A(n);
    rep(i,n) cin>>A[i];
    ll a=A[0];
    rep(i,n) a=gcd(a,A[i]);
    if(a!=1){
        cout<<"not coprime";
        return 0;
    }
    vec B=Era(1000000);
    map<int,int> D;
    rep(i,n){
        set<ll> C;
        while(A[i]!=1) C.insert(B[A[i]]),A[i]/=B[A[i]];
        for(auto itr=C.begin();itr!=C.end();itr++){
            if(D[*itr]){
                cout<<"setwise coprime";
                return 0;
            }
            D[*itr]++;
        }
    }
    cout<<"pairwise coprime";
}