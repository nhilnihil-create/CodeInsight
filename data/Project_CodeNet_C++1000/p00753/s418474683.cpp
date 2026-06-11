#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>

using namespace std;
 
const double eps=1e-10;

const int dy[]={-1,-1,0,1,1, 1, 0,-1};
const int dx[]={ 0, 1,1,1,0,-1,-1,-1};

int main()
{

	vector<long> prime;
	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);

	for(int i=7;prime.back()<123456*2;i+=2){
		bool ok=true;
		for(int j=0;prime[j]*prime[j]<=i && ok;j++){
			if(i%prime[j]==0) ok=false;
		}
		if(ok) prime.push_back(i);
//		if(ok) cout<<i<<endl;
	}

	long n;
	while(cin>>n,n){
		auto l=upper_bound(prime.begin(),prime.end(),n);
		auto r=lower_bound(prime.begin(),prime.end(),2*n);

		if(n==1) cout<<1<<endl;
		else cout<<r-l<<endl;
	}


	return 0;
}