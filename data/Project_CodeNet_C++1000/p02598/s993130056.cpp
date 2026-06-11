#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
#define inf 2147483647
#define range(x,a,b) (a)<=x&&x<=(b)
int n,k;
int a[200000];
bool can(int length){
	ll WorkCount=0;
	rep(i,n){
		WorkCount+=(a[i]+(length-1))/length-1;
	}
	if(WorkCount>k)return 0;
	else return 1;
}

int main(){
	cin>>n>>k;
	in(a,n);
	int left=0,right=1000000000;//2分探索(left<anser<=right)
	int middle;
	while(right-left!=1){
		middle=(left+right)/2;
		if(can(middle)){
			right=middle;
		}
		else{
			left=middle;
		}
	}
	cout <<right;
	return 0;
}