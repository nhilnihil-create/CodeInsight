#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ull n,a,b;
	cin >> n >> a >> b;
	if((b-a)%2==0)
		cout << (b-a)/2 << endl;
	else
		cout << min((a+b-1)/2,n-(a+b-1)/2) << endl;
}