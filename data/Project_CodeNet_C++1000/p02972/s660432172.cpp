#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    int N;
    cin>>N;
    vector<int> a(N),ans(N);
    rep(i,N){
        cin>>a.at(i);
    }
    for(int i=N;i>=1;i--){
        int count=0;
        for(int j=2;j*i<=N;j++){
            count+=ans.at(i*j-1);
        }
        if(abs(count-a.at(i-1))%2==1)ans.at(i-1)=1;
    }
    int M=0;
    rep(i,N){
        M+=ans.at(i);
    }
    cout<<M<<endl;
    rep(i,N){
        if(ans.at(i))cout<<i+1<<endl;
    }
}