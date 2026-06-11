#include<bits/stdc++.h>
using namespace std;
int k,ans;
int gcd(int x,int y) {
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
}
int main(){
	cin>>k;
	for (int i=1;i<=k;i++)
		for (int j=1;j<=k;j++)
			for (int l=1;l<=k;l++)
				ans+=gcd(gcd(i,j),l);
	cout<<ans<<endl;
	return 0;
}