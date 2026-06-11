#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
P<int,int> p[100005];
set<int> s;deque<int> v;
int n; 
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    FOR(i,1,n)cin>>p[i].F,p[i].S=i;
    int t=0,ans=0;
    sort(p+1,p+n+1,greater<P<int,int> >());
    FOR(i,1,n){
    	s.insert(p[i].S);if(i==1)continue;
    	set<int>::iterator t=s.lower_bound(p[i].S),iter=t;
    	v.clear();
    	v.PB(*iter);
    	int tl=0;
    	for(int j=0;j<2&&iter!=s.begin();j++){
    		iter--;v.PF((*iter));tl++;
    	}
    	iter=t;iter++;
    	for(int j=0;j<2&&iter!=s.end();j++){
    		v.PB((*iter));iter++;
    	}
    	//for(int j=0;j<v.size();j++)cout<<v[j]<<' ';cout<<tl<<'\n';
    	if(tl){
    		int s1,s2;
    		if(tl!=1){
    			s1=v[1]-v[0];
    		}else s1=v[0];
    		if(tl!=v.size()-1){
    			s2=v[tl+1]-v[tl];
    		}else s2=n-v[tl]+1;
    		ans+=s1*s2*p[i].F;
    	}
    	if(tl!=v.size()-1){
    		int s1,s2;
    		if(tl){
                s1=v[tl]-v[tl-1];
            }else s1=v[tl];
            if(tl!=v.size()-2){
                s2=v[tl+2]-v[tl+1];
            }else s2=n-v[tl+1]+1;
            ans+=s1*s2*p[i].F;
    	}
    }
    cout<<ans;
	RE 0;
}