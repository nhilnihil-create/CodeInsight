#include<iostream>
#include<string>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
	int x,k,d;
	cin>>x>>k>>d;
	int pl=(x%d+d)%d;
	if(abs(pl-x)/d%2!=k%2)
		pl-=d;
	cout<<(abs(pl-x)/d<=k?abs(pl):pl>=x?abs(x+d*k):abs(x-d*k))<<endl;
}
