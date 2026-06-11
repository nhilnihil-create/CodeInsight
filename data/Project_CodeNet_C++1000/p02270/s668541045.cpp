#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n,k;
ll A[100010];

bool f(ll p){
	ll temp=p;
	int x=0;
	for(int i =0;i<k;i++){
		while(temp>=A[x]){
			temp-=A[x];
			x++;
		}
		temp=p;
	}
	if(x>=n) return true;
	else return false;
}

ll binary_find(ll left,ll right){
	ll mid;
	while(left+1<right){
		mid=(left+right)/2;
		if(f(mid)) right=mid;
		else left=mid;
	}
	return right;
}

int main(){
	ll p,sum;
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		cin>>A[i];
		sum+=A[i];
	}
	p=binary_find(0,sum);
	cout<<p<<endl;
	return 0;
}
