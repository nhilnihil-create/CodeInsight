#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int N;
	cin>>N;
	
	vector<long long> A(N);
	long long X = 0;
	for(int i=0;i<N;i++){
		cin>>A[i];
		//cout<<(bitset<10>)A[i]<<endl;
	}
	
	vector<int> cnt(60,0);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<60;j++){
			if((((long long)1<<j)&A[i])!=0)cnt[j]++;
		}
	}
	
	long long ans = 0;
	
	for(int i=0;i<60;i++){
		if(cnt[i]%2==1){
			ans+=((long long)1<<i);
			for(int j=0;j<N;j++){
				if((((long long)1<<i)&A[j])!=0){
					A[j]-=((long long)1<<i);
				}
			}
		}
	}
	//for(int i=0;i<N;i++)cout<<(bitset<10>)A[i]<<endl;
//	cout<<endl;
	int last = 0;
	for(int i=59;i>=0;i--){
		long long a = ((long long)1<<i);
		int K = -1;
		for(int j=last;j<N;j++){
			if((A[j]&a)!=0){
				K=j;
				break;
			}
		}
		if(K==-1)continue;
		for(int j=0;j<N;j++){
			if(K==j)continue;
			if((A[j]&a)!=0){
				A[j] ^= A[K];
			}
		}
		swap(A[last],A[K]);
		last++;
		//for(int i=0;i<N;i++)cout<<(bitset<10>)A[i]<<endl;
		//cout<<endl;

	}
	
	long long a = 0;
	for(int i=0;i<N;i++){
		a^=A[i];
	}
	
	ans += a*2;
	
	cout<<ans<<endl;
		
		
	
	return 0;
}