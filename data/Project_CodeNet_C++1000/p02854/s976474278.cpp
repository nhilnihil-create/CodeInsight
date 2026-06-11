#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin >> n;
	vector<long long> v(n);
	long long sum=0;
	for(long long& x:v) {cin >> x;sum+=x;}
	long long half=0;

	for(long long i=0;i<n;i++){
		half+=v[i];
		if(half>=sum/2) {
			long long temp=half-v[i];
			cout << min(abs(half-(sum-half)),abs(temp-(sum-temp)));
			break;
		}
	}
	
			
	
}
