#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	multiset<long double> s;
	for(long long i=0;i<n;i++){
		long double a;
		cin >> a;
		s.insert(a);
	}set <long double> :: iterator it;
	it=s.begin();
	long double ans=*it;
	for (long long i = 1; i < n; i++)
	{
	    	long double x = *next(s.begin(), i);
	    	ans=(ans+x)/2;
	    }
	cout<<ans;
	return 0;
}