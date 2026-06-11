#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

ll N, K; 
vector<ll> A, F;

bool ok(ll n){
    ll cur=K;
    for(int i=0; i<N; i++){
        if(A[i]*F[i] > n){
            cur-=((A[i]*F[i]-n)+F[i]-1)/F[i];
        }
    }
    if(cur >= 0) return true;
    else return false;
}

int main(){
    cin >> N >> K;
    A.resize(N), F.resize(N);
    for(auto &x : A){
        cin >> x;
    }
    for(auto &x : F){
        cin >> x;
    }
    sort(all(A));
    sort(all(F), greater<ll>());
    ll l=-1, r=1e12+5;
    while(r-l > 1){
        ll mid=l+(r-l)/2;
        if(ok(mid)) r=mid;
        else l=mid;
    }
    cout << r << endl;
    return 0;
}