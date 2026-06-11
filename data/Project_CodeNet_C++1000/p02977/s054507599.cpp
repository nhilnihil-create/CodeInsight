#include<bits/stdc++.h>
#define e 1000000007
#define PB push_back
#define MP make_pair
#define lli long long int
#define pll pair< lli,lli >
#define pls pair< lli,string >
#define pii pair< int,int >
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x,y;
	cin>>n;
	x=log2(n);
	y=pow(2,x);
	if(y==n || n==1){
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<endl;
	for(int i=2;i<n;i+=2){
		cout<<1<<" "<<i<<endl;
		cout<<i<<" "<<i+1<<endl;
		cout<<1<<" "<<n+i+1<<endl;
		cout<<n+i+1<<" "<<n+i<<endl;
		if(i==2)cout<<n+i<<" "<<n+1<<endl;
	}
	if(n%2==0){
		cout<<n-2<<" "<<n+n<<endl;
		y=n^(n-2)^1;
		y+=n;
		cout<<y<<" "<<n<<endl;
	}
	return 0;
}