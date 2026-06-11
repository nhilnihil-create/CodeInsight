#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	vector<vector<long long>> hoge(10,vector<long long>(10));

	for(long long i=1;i<=n;i++){
		string s=to_string(i);
		long long a=s.at(0)-'0';
		long long b=*s.rbegin()-'0';

		hoge.at(a).at(b)++;
	}

	long long ans=0;

	for(long long i=0;i<=9;i++){
		for(long long j=0;j<=9;j++){
			ans+=hoge.at(i).at(j)*hoge.at(j).at(i);
		}
	}

	cout<<ans<<endl;

	return 0;
}
