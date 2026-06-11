#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)

vector<ll> fact(ll a){
    vector<ll>ans;
    vector<ll> hoge;
    for(ll i = 1;i*i<=a;i++){
        if(a%i==0) {
            ans.push_back(a/i);
            if(i*i!=a) hoge.push_back(i);
        }
    }
    rep(i,hoge.size()){
        ans.push_back(hoge[hoge.size()-1-i]);
    }
    return ans;
}

bool check(ll *A,ll val,int N,ll K){
    ll sum = 0;
    vector<ll> vec;
    rep(i,N){
        vec.push_back(A[i]-(A[i]/val)*val);
        sum+=A[i]-(A[i]/val)*val;
    }
    ll num = sum/val;
    sort(vec.begin(),vec.end());
    ll hoge=0;
    for(int i = vec.size()-1;num!=0;i--){
        num--;
        hoge += val - vec[i];
    }
    if(hoge<=K) return true;
    else return false;
}

int main(){
    int N;
    ll K;
    cin>>N>>K;
    ll A[500];
    ll sum = 0;
    rep(i,N) {cin>>A[i];sum+=A[i];}
    vector<ll> vals = fact(sum);
    rep(i,vals.size()){
        ll val = vals[i];
        if(check(A,val,N,K)){
            cout<<val<<endl;
            return 0;
        }
    }
    return 0;
}