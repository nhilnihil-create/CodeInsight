#include <bits/stdc++.h>
using namespace std;
#define ff(i,s,n) for(int i=s;i<n;i++)
#define fr(i,s,n) for(int i=n-1;i>=s;i--)
#define llu long long int
const int mod=1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	llu p=max((llu)a*c,max((llu)a*d,max((llu)b*c,(llu)b*d)));
	cout<<p;
	return 0;
}


//1
//7 2
//3 5 4 5 1 1 1
