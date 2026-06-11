#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

template <typename T,typename U>
struct compressor{
	vector<pair<T,U>> v;
	void add(T x,U y){
		v.emplace_back(x,y);
	}
	
	void compress(){
		sort(v.begin(),v.end());
		
		vector<pair<T,U>> t;
		rep(i,v.size()){
			if(t.size()!=0 && t.back().first == v[i].first){
				t.back().second = func(t.back().second,v[i].second);
			}
			else{
				t.push_back(v[i]);
			}
		}
		swap(v,t);
		
	}

	U func(U a,U b){
		return a+b;
	}

	int size(){
		return v.size();
	}
	
	U get(int p){
		return v[p].second;
	}
	
	U operator[] (T &x){
		return lower_bound(v.begin(),v.end(),x)->second;
	}
};

int main(){

	int N;
	cin>>N;
	
	compressor<string,int> C;
	
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		C.add(s,1);
	}
	
	C.compress();
	
	long long ans = 0;
	
	rep(i,C.size()){
		long long t = C.get(i);
		ans += t * (t-1) / 2;
	}
	
	cout<<ans<<endl;

	return 0;
}

