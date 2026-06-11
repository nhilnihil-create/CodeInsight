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
    int N,M;cin>>N>>M;
    vector<int>a(N);
    int sum=0;
    rep(i,N){
        cin>>a.at(i);
        sum+=a.at(i);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int lim;
    if(sum%(4*M)==0){
        lim=sum/(4*M);
    }else{
        lim=sum/(4*M)+1;
    }
    int sum2=0;
    rep(i,N){
        if(a.at(i)>=lim){
            sum2++;
        }
        if(sum2>=M){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}