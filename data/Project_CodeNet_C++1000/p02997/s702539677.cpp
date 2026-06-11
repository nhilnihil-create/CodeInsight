#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,k;cin>>n>>k;
    if(k>(n-1)*(n-2)/2){
        cout<<-1<<endl;
        return 0;
    }
    cout<<n*(n-1)/2-k<<endl;
    rep2(i,2,n+1)cout<<1<<" "<<i<<endl;
    int res=(n-1)*(n-2)/2-k,u=2,v=3;;
    while(res>0){
        cout<<u<<" "<<v<<endl;
        if(v==n){
            u++;
            v=u+1;
        }
        else v++;
        res--;
    }
}