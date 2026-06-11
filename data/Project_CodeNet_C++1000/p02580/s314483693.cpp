

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define w(t) int t;cin>>t;while(t--)
#define pb push_back
#define mk make_pair
#define ascSort(v) sort(v.begin(), v.end())
#define descSort(v) sort(v.begin(), v.end(), greater<int>())
#define ff first
#define ss second
#define pi pair<int,int>
#define vi vector<int>
#define umapi unordered_map<int,int>

const int m=998244353;
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>PBDS;

void FIO(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
}



int32_t main(){
	
	//FIO();
	int h,w;cin>>h>>w;
	vi row(h,0),col(w,0);
	int m;cin>>m;
	set<pi> s;
	for(int i=0; i<m; i++){
		int x,y;cin>>x>>y;
		x--;y--;
		s.insert({x,y});
		row[x]++;col[y]++;
	}

	int mxr=row[0],mxc=col[0];
	for(auto x:row)
		mxr=max(mxr,x);
	for(auto x:col)
		mxc=max(mxc,x);
	vi ansr,ansc;	
	for(int i=0; i<h ;i++){
		if(row[i]==mxr)
			ansr.pb(i);
	}
	for(int i=0; i<w ;i++){
		if(col[i]==mxc)
			ansc.pb(i);
	}
	int x=ansr.size(),y=ansc.size();
	if(x*y>(int)3*100000){
		cout<<mxr+mxc<<"\n";
		return 0;
	}
	else{
		for(int i=0; i<(int)ansr.size(); i++){
			for(int j=0; j<(int)ansc.size(); j++){
				if(s.find({ansr[i],ansc[j]})==s.end()){
					cout<<mxr+mxc;
					return 0;
				}
				//return 0;
			}
		}
	}		
	cout<<mxr+mxc-1;
		
	
	

	return 0;
	
		
}


