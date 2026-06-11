#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
	ll N,K;
	cin>>N>>K;
	vector<int> P(N);
	for (int i = 0; i < N; i++){
		int tmp;cin>>tmp;
		P[i]=tmp-1;
	}
	vector<ll> C(N,0);
	for (int i = 0; i < N; i++){
		cin>>C[i];
	}
	vector<ll> from(N,0);
	for (int i = 0; i < N; i++){
		int start=i;
		int loop_len=1;
		int next=P[start];
		ll loop_sum=C[next];
		while(next!=start){
			next=P[next];
			loop_len++;
			loop_sum+=C[next];
		}
		next=P[start];
		from[start]=C[next];
		ll tmpsum=C[next];
		if(K<loop_len){
			for (int j = 1; j < K; j++){
				next=P[next];
				tmpsum+=C[next];
				from[start]=max(from[start],tmpsum);
			}
		}else if(loop_sum>0){
			for (int j = 1; j < K%loop_len+loop_len; j++){
				next=P[next];
				tmpsum+=C[next];
				from[start]=max(from[start],tmpsum);
			}
			from[start]+=loop_sum*(K/loop_len-1);
		}else{
			for (int j = 1; j < loop_len; j++){
				next=P[next];
				tmpsum+=C[next];
				from[start]=max(from[start],tmpsum);
			}
		}
	}
	sort(from.begin(),from.end());
	cout<<from[N-1]<<endl;
}