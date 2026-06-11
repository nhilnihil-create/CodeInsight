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

const double pi=3.1415926535897932384626;

void koch(int n,pair<double,double> a,pair<double,double> b){
    if(n==0)return;
    decp(10);
    pair<double,double> s=mp((2*a.first+b.first)/3,(2*a.second+b.second)/3);
    pair<double,double> t=mp((a.first+2*b.first)/3,(a.second+2*b.second)/3);
    pair<double,double> u=mp((t.first-s.first)*cos(pi/3)-(t.second-s.second)*sin(pi/3)+s.first,(t.first-s.first)*sin(pi/3)+(t.second-s.second)*cos(pi/3)+s.second);
    koch(n-1,a,s);
    cout<<s.first<<" "<<s.second<<endl;
    koch(n-1,s,u);
    cout<<u.first<<" "<<u.second<<endl;
    koch(n-1,u,t);
    cout<<t.first<<" "<<t.second<<endl;
    koch(n-1,t,b);
}

int main(){
    int n;cin>>n;
    pair<double,double> a=mp(0,0);
    pair<double,double> b=mp(100,0);
    cout<<0<<" "<<0<<endl;
    koch(n,a,b);
    cout<<100<<" "<<0<<endl;
}
