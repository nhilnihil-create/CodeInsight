#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	string s;
	cin>>n>>s;
	long long ans=0;

	for(long long i=0;i<=999;i++){
		string S=to_string(i);

		while(S.size()<3){
			S="0"+S;
		}

		long long now=0;

		for(long long j=0;j<n;j++){
			if(s.at(j)==S.at(now)) now++;
			if(now==3){
				ans++;
				break;
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}
