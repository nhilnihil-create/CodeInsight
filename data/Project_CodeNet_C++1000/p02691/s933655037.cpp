#include<bits/stdc++.h>
#include <time.h>
using namespace std;
#include <math.h>
#define ll long long 
// to increase precision
// std::cout<<std::fixed;
// 	std::cout<<std::setprecision(6)<<z;
//clock_t tStart = clock();
//printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define max1 200001


int main(){	
	
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}map<long long int,int>mp;
	mp[1+a[1]]+=1;
	long long int ans=0;
	for(int i=2;i<=n;i++){
		if(i-a[i]>0)
			ans+=mp[i-a[i]];
		mp[i+a[i]]+=1;
	}
	cout<<ans<<endl;
	
}