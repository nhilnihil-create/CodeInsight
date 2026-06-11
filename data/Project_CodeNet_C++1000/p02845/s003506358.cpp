#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	long mod = 1e9+7;
	int N;
	cin>>N;
	int A[N];
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	map<int, long>hat;
	long ans = 1;
	hat[-1] = 3;
	for(int i=0;i<N;++i){
		//cout<<i<<" "<<hat[A[i]]<<" "<<hat[A[i]-1]<<endl;
		ans *= hat[A[i]-1]-hat[A[i]];
		ans %= mod;
		hat[A[i]]++;
		if(hat[A[i]]>3 | hat[A[i]]>hat[A[i]-1]) ans*= 0;
	}
	cout<<ans<<endl;
}
