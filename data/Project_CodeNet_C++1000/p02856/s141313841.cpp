#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset> 
#include <cstdio> 
#include <vector>
using namespace std;
int n;
int main(){
	cin>>n;
	long long sum=0,bitt=0,ans=0;
	while(n--){
		long long x,y;
		cin>>x>>y;
		if(x==0)ans+=y;
		else{
			sum+=x*y;
			bitt+=y;
		}
	}
	ans=ans+sum/9+bitt-1;
	if(sum%9==0)ans--;
	cout<<ans;
	return 0;
}
