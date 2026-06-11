#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;int D;cin>>N>>D;
    vector<vector<int>>X(N,vector<int>(D));
    rep(i,N)rep(j,D){
        cin>>X.at(i).at(j);
    }
    double l=0;
    int sum=0;
    int ans=0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            for(int k=0;k<D;k++){
                sum+=(X.at(i).at(k)-X.at(j).at(k))*(X.at(i).at(k)-X.at(j).at(k));
            }
            l=sqrt(sum);
            if(l==(int)l){
                ans++;
            }
            sum=0;
        }
    }
    cout<<ans<<endl;
}

