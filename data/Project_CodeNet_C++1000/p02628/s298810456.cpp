#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,N) for(int i=0;i<(N);i++)
using namespace std;

int main(){
	int K,N;
	long long sum=0;
	cin>>N>>K;
	vector<int> p(N);
	rep(i,N)cin>>p[i];
	sort(p.begin(),p.end());
	rep(i,K){
		sum+=p[i];
	}
	cout<<sum<<endl;
}