#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	vector<long long> hoge(n);
	long long sum=0;

	for(int i=0;i<n;i++){
		cin>>hoge.at(i);
		sum+=hoge.at(i);
	}

	long long ans=inf*10000;
	long long pre=0;

	for(auto a:hoge){
		pre+=a;
		sum-=a;
		ans=min(ans,abs(sum-pre));
	}

	cout<<ans<<endl;

	return 0;
}
