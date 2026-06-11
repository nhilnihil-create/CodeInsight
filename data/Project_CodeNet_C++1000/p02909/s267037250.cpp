#include <bits/stdc++.h>
using namespace std;
#define	fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(n,arr)  for(int i=0;i<n;i++)cin>>arr[i]; // 0 => n
#define	pi 3.14159265358979323846
#define	endl "\n"
#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+5 , oo=0x3f3f3f3f , mod=1e9+7;

int main(){
	string a="Sunny";
	string b="Cloudy";
	string c="Rainy";
	string s;cin>>s;
	if(s==a)
		cout<<b;
	else if(s==b)
		cout<<c;
	else if(s==c)
		cout<<a;
	
	return 0;
}