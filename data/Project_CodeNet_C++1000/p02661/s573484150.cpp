#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
ll MOD=1e9+7;

struct seg{
    ll l,r;
};
bool comp1(seg p,seg q){
    if(p.l==q.l) return p.r<q.r;
    return p.l<q.l;
}
bool comp2(seg p,seg q){
    if(p.r==q.r) return p.l<q.l;
    return p.r<q.r;
}
int main(){
    int n;cin>>n;
    vector<seg> s(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        s[i]=seg{a,b};
    }
    if(n%2==1){
        sort(s.begin(),s.end(),comp1);
        int ml=s[n/2].l;
        sort(s.begin(),s.end(),comp2);
        int mr=s[n/2].r;
        cout<<max(mr-ml+1,0)<<endl;
        return 0;
    }else{
        sort(s.begin(),s.end(),comp1);
        int ml=s[n/2-1].l+s[n/2].l;
        sort(s.begin(),s.end(),comp2);
        int mr=s[n/2-1].r+s[n/2].r;
        cout<<max(mr-ml+1,0)<<endl;
        return 0;
    }
}