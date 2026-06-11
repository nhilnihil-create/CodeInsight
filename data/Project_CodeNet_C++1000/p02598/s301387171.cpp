
#include <bits/stdc++.h>


using namespace std;
double pi=3.14159265358979323846264338;
long long sum;
long long ma;
long long n,k,st;
long long pr(long long a, long long b){
	long long k=1;
	if(b==0)return 1;
	
	for(int i=0;i<b;i++)k=k*10;
	return k;
}
long long arr[200001];
bool che(long long a){
	long long cur=0;
	for(int i=0;i<n;i++){
		cur+=(arr[i]+a-1)/(a)-1;
	}
	if(cur<=k)return true;
	return false;
}
int main(){
	sum=0;
	ma=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		long long cur;
		cin>>cur;
		arr[i]=cur;
		ma=max(ma,cur);
		sum+=cur;
	}
	st=(sum+n+k-1)/(n+k);
	//cout<<st<<endl;
	long long ls=st;
	long long to=ma;
	long long mid;
	while(ls<=to){
		mid=(ls+to)/2;
		if(!che(mid))ls=mid+1;
		else to=mid-1;
	}
	//cout<<ls<<" "<<to<<endl;
	for(int i=max(1LL,ls-4);i<=to+4;i++){
		if(che(i)){cout<<i<<endl;return 0;}
	}
			
	return 0;
}