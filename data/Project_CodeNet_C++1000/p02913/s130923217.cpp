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
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int l=0;int r=n;int m=(l+r)/2;bool can;string tmp;
    while(r-l>1){
        m=(l+r)/2;
        if(n<2*m){
            r=m;
            continue;
        }
        can=false;
        set<string> ss;
        queue<string> q;
        rep(i,m)q.push(s.substr(i,m));
        for(int i=m;i+m-1<n;i++){
            ss.insert(q.front());q.pop();
            tmp=s.substr(i,m);
            if(ss.count(tmp)){
                can=true;
                break;
            }
            q.push(tmp);
        }
        if(can)l=m;
        else r=m;
    }
    cout<<l<<endl;
}