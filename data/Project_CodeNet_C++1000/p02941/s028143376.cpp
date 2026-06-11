#include<bits/stdc++.h>
using namespace std;
#define se second
#define fi first
#define ll long long
#define ld long double
#define pll pair<ll ,ll >
#define pii pair<int, int> 
#define mod 1000000007
ll power(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b%2!=0) res=(res*a);
        a=(a*a);
        b/=2;
        if(res>INT_MAX){
            return INT_MAX;
        }
    }
    return res;
}
ll ncr(ll n,ll k){
    if(k==0||k==n) return 1ll;
    if(k>n-k) k=n-k;
    ll pro=1;
    for(ll i=0;i<k;i++){
        pro=(pro*(n-i));
        pro/=(i+1);
    }
    return pro;
}
vector<int> prime;
void seive(){
    vector<bool > isprime(101,true);
    for(int i=2;i*i<=100;i++){
        if(isprime[i]){
            for(int j=i*i;j<=100;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<=100;i++){
        if(isprime[i]) prime.push_back(i);
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,a;
    cin>>n;
    vector<ll> A,B;
    priority_queue<pll> pq;
    for(int i=0;i<n;i++) {
        cin>>a;
        A.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin>>a;
        B.push_back(a);
        pq.push({a,i});
    }
    ll count=0;
    while(!pq.empty()){
        pll p=pq.top();
        pq.pop();
        ll pr=(p.se-1+n)%n;
        ll nxt=(p.se+1)%n;
        //cout<<pr<<" "<<nxt<<endl;
        if(B[p.se]==A[p.se]){
            continue;
        }
        if(B[p.se]<A[p.se]) {
            cout<<"-1";
            return 0;
        }
        if(A[p.se]>B[pr] && A[p.se]>B[nxt]){
            if((B[p.se]-A[p.se])%(B[pr]+B[nxt])!=0) {
                cout<<"-1";
                return 0;
            }
            count+=(B[p.se]-A[p.se])/(B[pr]+B[nxt]);
            B[p.se]=A[p.se];
            continue;
        }
        if(B[p.se]<B[pr]+B[nxt]) {
            cout<<"-1";
            return 0;
        }
        count+=B[p.se]/(B[pr]+B[nxt]);
        B[p.se]%=(B[pr]+B[nxt]);
        if(B[p.se]==0) {
            cout<<"-1";
            return 0;
        }
        pq.push({B[p.se],p.se});
    }
    cout<<count;
    return 0;
}
