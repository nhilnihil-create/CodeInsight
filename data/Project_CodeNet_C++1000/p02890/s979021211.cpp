#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;


vector<int> org;
set<int> nz;
vector<int> ds,ds0,fs;
int f(int K)
{
	if(ds.size()<K){
		return 0;
	}
	auto p=[&](int t,int d){
		if(fs[t]!=K){
			org.push_back(t);
			fs[t]=K;
		}
		ds[t]+=d;
		if(abs(ds[t])==1){
			nz.insert(t);
		}
		else if(ds[t]==0){
			nz.erase(t);
		}
#if 0
		for(auto v:ds){
			cerr << v << ", ";
		}
		cerr << endl;
		for(auto n:nz){
			cerr << n << endl;
		}
		if((ds[t]!=0)!=(nz.count(t)!=0)){
			cerr << t << ", " << ds[t] << ", " << nz.count(t) << ", " << d << endl;
		}
#endif
	};
	org.clear();
	int s=K-1,t=K-1;
	int ret=0;
	while(1){
		if(ds[t]==0){
			auto it=lower_bound(nz.begin(),nz.end(),t);
			if(it==nz.end()){
				t=ds.size()-1;
			}
			else{
				t=*it;
			}
		}
		if(s>0&&ds[s-1]==0){
			auto it=lower_bound(nz.begin(),nz.end(),s);
			if(it==nz.begin()){
				s=0;
			}
			else {
				it--;
				s=*it+1;
			}
		}

		if(t==s){
			p(t,-1);
		}
		else{
			p(t,-1);
			if(s>0){
				p(s-1,-1);
			}
			int u=t-(K-s);
			if(u>=0){
				p(u,1);
			}
			if(u<K-1)
			{
				s=u+1;
			}
			else{
				t=u;
			}
		}
		if(ds.back()<0)break;
		ret++;
	}
	for(auto t:org){
		ds[t]=ds0[t];
		if(ds[t]){
			nz.insert(t);
		}
		else{
			nz.erase(t);
		}
	}
	return ret;
}

void solve(long long N, std::vector<long long> A){
	sort(A.begin(),A.end());
	int k=1;
	for(int i=1;i<N;i++){
		if(A[i]==A[i-1]){
			k++;
		}
		else{
			ds.push_back(k);
			k=1;
		}
	}
	ds.push_back(k);
	sort(ds.begin(),ds.end(),greater<int>());
	for(int i=0;i<ds.size()-1;i++)
	{
		ds[i]-=ds[i+1];
		if(ds[i]){
			nz.insert(i);
		}
	}
	nz.insert(ds.size()-1);
#if 0
	cerr << "aaa ";
	for(int i=0;i<ds.size();i++){
		cerr << ds[i];
	}
	cerr << endl;
#endif
	ds0=ds;
	fs.resize(ds.size());
#if 0
	for(auto v:ds){
		cerr << v << ", ";
	}
	cerr << endl;
	for(auto n:nz){
		cerr << n << endl;
	}
#endif
	for(int i=1;i<=N;i++){
		printf("%d\n",f(i));
	}
}


int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}


