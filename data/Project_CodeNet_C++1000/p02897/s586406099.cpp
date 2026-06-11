#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int even=(n/2);
	int odd=n-(n/2);
	float pr=(float(odd))/n;
	cout<<pr;
	return 0;
}