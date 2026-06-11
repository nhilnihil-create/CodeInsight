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
    int n,k,c;cin>>n>>k>>c;
    string s;cin>>s;
    vin maru;
    rep(i,n)if(s[i]=='o')maru.push_back(i+1);
    int m=maru.size();
    vin maximuml(m);//maru[i]の日に働くとしたとき最大で何回目の仕事になるか
    int l,r,mid;
    rep(i,m){
        l=-1;r=i;
        while(r-l>1){
            mid=(l+r)/2;
            if(maru[mid]+c<maru[i])l=mid;
            else r=mid;
        }
        if(l==-1)maximuml[i]=1;
        else maximuml[i]=maximuml[l]+1;
    }
    vin maximumr(m);//maru[i]の日に働くとしたときmaru[i]の日の仕事も含めてあと最大で何回働けるか
    for(int i=m-1;i>=0;i--){
        l=i;r=m;
        while(r-l>1){
            mid=(l+r)/2;
            if(maru[i]+c<maru[mid])r=mid;
            else l=mid;
        }
        if(r==m)maximumr[i]=1;
        else maximumr[i]=maximumr[r]+1;
    }
    vin maximum(m);//maru[i]の日に働くとしたとき次に働くことができる最も遅い日
    rep(i,m){
        if(maximuml[i]>=k){
            maximum[i]=inf;
            continue;
        }
        l=i;r=m;
        while(r-l>1){
            mid=(l+r)/2;
            if(maximuml[i]+maximumr[mid]>=k)l=mid;
            else r=mid;
        }
        if(maru[i]+c>=maru[l])maximum[i]=-inf;//maru[i]に働くことはできない
        else maximum[i]=l;
    }
    //各iに対してj<iなる任意のjに対してmaximum[j]<=iならばmaru[i]日目は必ず働かなければならない
    vin ans;int res;
    if(m==1||m>1&&maximumr[1]<k)ans.push_back(maru[0]);//i=0だけは別で考える
    rep(i,m){
        res=i-1;
        while(res>=0){
            if(maximum[res]!=-inf){
                if(maximum[res]<=i)ans.push_back(maru[i]);
                break;
            }
            res--;
        }
    }
    rep(i,ans.size())cout<<ans[i]<<endl;
    //rep(i,m)cout<<maru[i]<<" "<<maximum[i]<<endl;
}