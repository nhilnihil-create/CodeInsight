#include<bits/stdc++.h>
#define tmp(x) std::cout<<"& "<<(x)<<" &\n"
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;

using namespace std;
const int maxn=3e5+100;
int n,t;
int h,w,m;
vector<int> hh[maxn];
vector<int> ww[maxn];
set<pair<int,int> >s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>w>>m;
   int xx=0,yy=0;
    rep(i,1,m){
        int x,y;
        cin>>x>>y;
        hh[x].push_back(y);
        ww[y].push_back(x);
        xx=max(xx,(int)hh[x].size());
        yy=max(yy,(int)ww[y].size());
        s.insert(make_pair(x,y));
    }
    vector<int> ax,ay;
    rep(i,1,h)if(hh[i].size()==xx)ax.push_back(i);
    rep(i,1,w)if(ww[i].size()==yy)ay.push_back(i);
    int ans=xx+yy-1;
    rep(i,0,ax.size()-1){
    	rep(j,0,ay.size()-1){
    		if(!s.count(make_pair(ax[i],ay[j]))){
    			cout<<ans+1;return 0;
			}
		}
	}
    cout<<ans;



    return 0;
}
