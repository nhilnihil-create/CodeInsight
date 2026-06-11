#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	int k,n;
	cin>>k>>n;
	vector<int>a(n);
	long long int sum = 0;
	int before,now;
	cin>>a[0];
	before=a[0];
	for(int i=1;i<n;i++){
		cin>>now;
		a[i]=now-before;
		before = now;
	}
	a[0]+=k-before;
	long long int max=-1;
	rep(i,n){
		if(max<a[i])max = a[i];
	}
	cout<<k-max<<endl;
	return 0;
}