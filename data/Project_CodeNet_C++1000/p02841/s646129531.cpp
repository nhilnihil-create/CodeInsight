#include <bits/stdc++.h>
//#pragma GCC optimize "-O3"
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll infll=(1ull<<63)-1,mod=1e9+7;
const int inf=(1ull<<31)-1;
int m1,d1,m2,d2;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);cout.precision(18);
	cin>>m1>>d1>>m2>>d2;
	if (m1!=m2)
		cout<<"1";
	else 
		cout<<"0";
	return 0;
}