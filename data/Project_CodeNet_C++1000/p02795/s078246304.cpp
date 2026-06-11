#include <bits/stdc++.h>
#define pb push_back
#define sz(a) int(a.size())
#define re return
#define all(a) a.begin(),a.end()
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	a=max(a,b);
	cout<<(c+a-1)/a;
	re 0;
}