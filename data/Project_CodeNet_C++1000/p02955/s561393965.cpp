#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N,K;
int A[500];
signed main(){
    int sum=0;
    cin>>N>>K;
    rep(i,N){
        cin>>A[i];sum+=A[i];
    }
    vector<int>v;
    for(int i=1;i*i<=sum;i++){
        if(sum%i)continue;
        v.push_back(i);
        if(i*i!=sum)v.push_back(sum/i);
    }
    int ans=0;
    for(int i:v){
        int nesum=0,posum=0;
        vector<P>vec;
        rep(j,N){
            int ne=A[j]%i;
            int po=(i-A[j]%i)%i;
            vec.push_back({ne,po});
        }
        sort(all(vec));
        rep(j,N)posum+=vec[j].second;
        rep(j,N){
            if(posum==nesum){
                if(nesum<=K){
                    chmax(ans,i);break;
                }
            }
            nesum+=vec[j].first;
            posum-=vec[j].second;
        }
        if(posum==nesum){
            if(nesum<=K){
                chmax(ans,i);
            }
        }
    }
    cout<<ans<<endl;
}