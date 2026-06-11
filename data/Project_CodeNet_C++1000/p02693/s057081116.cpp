#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define ll long long
#define pb push_back
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug cout<<"Debugging.."<<endl
using namespace std;
int main()
{
	faster;

	int k,a,b;
	cin>>k;
	cin>>a>>b;
	if(a%k==0 || b%k==0)cout<<"OK";
	else if(a/k != b/k)cout<<"OK";
	else
	cout<<"NG";
}


