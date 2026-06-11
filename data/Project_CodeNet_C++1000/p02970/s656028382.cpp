#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,d;
	cin >> n >> d;
	d *=2;d++;
	cout<<(d+n-1)/d<<endl;
}