#include<bits/stdc++.h>
using namespace std;

#define mod      1e9+7;
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n;
	 cin>>n;
	 int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		/*if(a[i]%10==0 && a[i]%3==0){
			cout<<"DENIED\n"; return 0;
		}*/
		if(a[i]%2==0){
			if(a[i]%5!=0 && a[i]%3!=0){
				cout<<"DENIED\n"; return 0;
			}
		}
	}
	cout<<"APPROVED\n";
	return 0;
}