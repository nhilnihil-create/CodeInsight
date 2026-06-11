#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define vll vector<ll>
#define sz size()
#define pb emplace_back
#define mp make_pair
#define MOD 1000000007
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL))
const int N = 100005;

int main()
{
	ll a,b;
	cin>>a>>b;
	if(a==1 && b==1)
	cout<<"1000000";
	else if((a==1&&b==2)||(a==2 && b==1))
	cout<<"500000";
	else if((a==2 &&b==2)||(a==1&&b==3)||(a==3 &&b==1))
	cout<<"400000";
	else if((a==2 && b==3)||(a==3 && b==2))
	cout<<"300000";
	else if(a==3 &&b==3)
	cout<<"200000";
	else
	{
		if(a==1 ||b==1)
		cout<<"300000";
		else if(b==2 ||a==2)
		cout<<"200000";
		else if(a==3 ||b==3)
		cout<<"100000";
		else 
		cout<<"0";
	}
}