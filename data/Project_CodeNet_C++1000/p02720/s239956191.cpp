#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>ele;
ll Pow[12];

void solve(int pos,int cur,ll now,int mx)
{
	if(cur<0||cur>9){
		return;
	}
	if(pos==0){
		ele.push_back(now+cur);
		return;
	}
	now += cur*Pow[pos];
	int lmt;
	if(mx==0){
		lmt = 9;
	}
	else{
		lmt = cur+1;
	}
	for(int i=cur-1;i<=lmt;i++){
		solve(pos-1,i,now,max(mx,i));
	}
}
int main()
{
	Pow[0] = 1;
	for(int i=1;i<=9;i++){
		Pow[i] = Pow[i-1]*10;
	}
	for(int i=0;i<=9;i++){
		solve(9,i,0,i);
	}
	int k;
	scanf("%d",&k);
	sort(ele.begin(),ele.end());
	printf("%lld\n",ele[k]);
}
