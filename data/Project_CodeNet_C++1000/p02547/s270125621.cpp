#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int a[105][2];

int main()
{
	bool flag=false;
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
	for(int i=1;i<=n-2;i++){
		if(a[i][0]==a[i][1]&&a[i+1][0]==a[i+1][1]&&a[i+2][0]==a[i+2][1]) flag=true;
	}
	if(flag) cout<<"Yes";
	else cout<<"No";
	return 0;	
} 