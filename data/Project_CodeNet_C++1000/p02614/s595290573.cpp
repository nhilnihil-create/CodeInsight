#include<bits/stdc++.h>
#define M_PI       3.14159265358979323846
#define Speed_UP  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define 	pb	push_back 
#define 	ff	first 
#define 	ss	second 
#define sz(x) (int)x.size()
#warning Remeber to change t
using namespace std;
typedef long long ll;
inline void setIO(string name="") {
	#ifndef ONLINE_JUDGE 
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
	#endif
	}
	ll const mx=7;
	ll h,w,k;
	vector<vector<char>>ch(mx,vector<char>(mx));
	
	bool ok(ll a,ll b,vector<vector<char>>ch){
		ll count=0;
		for(ll i=0;i<h;i++){
			if(a&(1<<i)){
				for(int j=0;j<w;j++){
					ch[i][j]='R';
				}
			}
		}
		
		for(ll i=0;i<w;i++){
			if(b&(1<<i)){
				for(int j=0;j<h;j++){
					ch[j][i]='R';
				}
			}
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(ch[i][j]=='#')
					count++;
				}
			}
		if(count==k)
			return 1;
		
		return 0;
		
		
	}

int main(){
	Speed_UP
	ll t;
	t=1;
	while(t--){
		cin>>h>>w>>k;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>ch[i][j];
		ll ans=0;
		for(ll a=0;a<(1<<h);a++){
			for(ll b=0;b<(1<<w);b++){
				if(ok(a,b,ch))
					ans++;
			}
		}
		
		cout<<ans;
		
		
	}





}
