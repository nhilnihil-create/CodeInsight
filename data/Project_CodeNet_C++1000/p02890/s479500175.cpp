#include <bits/stdc++.h>
using namespace std;

map<int,int> m;
map<int,int> mp;

int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int A;
		cin >> A;
		A--;
		if(m.find(A)!=m.end())m[A]++;
		else m.insert(make_pair(A,1));
	}
	
	for(auto it=m.begin();it!=m.end();it++){
		int B=it->second;
		if(mp.find(B)!=mp.end())mp[B]++;
		else mp.insert(make_pair(B,1));
	}
	
	vector<pair<int,int>> mpmp;
	for(auto it=mp.begin();it!=mp.end();it++){
		mpmp.push_back(*it);
	}
	int M=mpmp.size();
	
	for(int K=1;K<=N;K++){
		int ok=0,ng=N/K+1;
		while(abs(ok-ng)>1){
			int mid=(ok+ng)/2;
			long long tmp=0;
			for(int i=0;i<M;i++){
				int C=mpmp[i].first,D=mpmp[i].second;
				tmp+=min(mid,C)*D;
			}
			if(tmp>=(long long)mid*K)ok=mid;
			else ng=mid;
		}
		printf("%d\n",ok);
	}
	
	return 0;
}