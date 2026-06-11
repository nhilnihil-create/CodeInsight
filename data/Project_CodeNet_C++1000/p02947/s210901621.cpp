#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

template <typename T>
struct compressor{
	vector<T> v;
	void add(T &x){
		v.push_back(x);
	}
	
	void compress(bool f = true){
		sort(v.begin(),v.end());
		if(f)v.erase(unique(v.begin(),v.end()),v.end());
	}

	int size(){
		return v.size();
	}
	
	int operator[] (T &x){
		return distance(v.begin(),lower_bound(v.begin(),v.end(),x));
	}
	
	T get(int id){
		return v[id];
	}
	
	int count(int id){
		if(id!=0 && v[id]==v[id-1])return 0;
		return distance(lower_bound(v.begin(),v.end(),v[id]),upper_bound(v.begin(),v.end(),v[id]));
	}
	
};

int main(){

	int N;
	cin>>N;
	
	compressor<string> C;
	
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		C.add(s);
	}
	
	C.compress(false);
	
	long long ans = 0;
	
	rep(i,N){
		long long t = C.count(i);
		ans += t * (t-1) / 2;
	}
	
	cout<<ans<<endl;

	return 0;
}

