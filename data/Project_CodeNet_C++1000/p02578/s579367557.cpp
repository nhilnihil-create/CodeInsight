#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int main()
{
	int n;
	cin >> n;
	ll x[MAXN];
	ll ans=0;
	for(int i=0;i<n;i++){
		cin >> x[i];
		if(i!=0){
			if(x[i]<x[i-1]){
				ans=ans+x[i-1]-x[i];
				x[i]=x[i-1];
			}
		}
	}
	cout << ans << endl;
	return 0;
}