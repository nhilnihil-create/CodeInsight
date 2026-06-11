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
    int n;cin>>n;
    vin p(n);
    map<int,int> num;
    rep(i,n){
        cin>>p[i];
        num[p[i]]=i+1;
    }
    set<int> r;
    rep(i,n+2)r.insert(i);//考えている数字より大きい数字の場所を残しておく
    ll tmp,sum,ans=(ll)0;
    ll l1,l2,r1,r2;//l1:iより小さいまだ残ってる数字の中でiに一番近い数字の場所 l2:iに二番目に近い r1,r2も同様
    rep2(i,1,n){
        tmp=num[i];
        r.erase(tmp);
        l1=*(--r.lower_bound(tmp));//upper is also ok
        l2=(l1!=0)?*(--r.lower_bound(l1)):0;
        r1=*(r.upper_bound(tmp));//lower is also ok
        r2=(r1!=n+1)?*(r.upper_bound(r1)):n+1;
        sum=(l1-l2)*(r1-tmp)+(tmp-l1)*(r2-r1);
        //cout<<i<<" "<<sum<<" "<<l1<<" "<<l2<<" "<<tmp<<" "<<r1<<" "<<r2<<endl;
        sum*=(ll)i;
        ans+=sum;
    }
    cout<<ans<<endl;
}