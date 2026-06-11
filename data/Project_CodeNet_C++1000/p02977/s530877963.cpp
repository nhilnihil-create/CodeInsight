#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int,int>P;
#define F first
#define S second

main(){
	int n;
	cin>>n;
	int N = n;
	if(__builtin_popcount(n)==1){
		cout<<"No"<<endl;
		return 0;
	}

	cout<<"Yes"<<endl;

	int p=0,cnt=0;
	if(N%2==0)p=1,N--;

	while(N!=1){
		cnt+=4;
		cout<<1<<' '<<N-1<<endl;
		cout<<N-1<<' '<<N<<endl;
		cout<<1<<' '<<n+N<<endl;
		cout<<n+N<<' '<<n+N-1<<endl;
		N-=2;
	}
	cout<<n+1<<' '<<3<<endl;cnt++;
	if(p){
		cout<<n+n-1<<' '<<n+n<<endl;cnt+=2;
		cout<<n<<' '<<((n-1)^n^1)<<endl;
	}
	//cout<<cnt<<endl;
}