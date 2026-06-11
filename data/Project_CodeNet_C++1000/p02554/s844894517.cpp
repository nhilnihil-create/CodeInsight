#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
const int mod=1e9+7;
int n;
int fn(int p){
	int j=1;
	for (int i=0;i<n;i++)
		j=(j*p)%mod;
	re j;
}
void sol(){
	cin>>n;
	cout<<(fn(10)-2*fn(9)+fn(8)+10*mod)%mod;
}
signed main()
{
	sol();
	re 0;
}
