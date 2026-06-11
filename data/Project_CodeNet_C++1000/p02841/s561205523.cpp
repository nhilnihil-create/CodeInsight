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
	ll m1,d1,m2,d2;
	cin>>m1>>d1>>m2>>d2;
	if(m1==1 && d1==31)
	cout<<"1";
	else if(m1==2 && d1==28)
	cout<<"1";
	else if(m1==3 && d1==31)
	cout<<"1";
	else if(m1==4 && d1==30)
	cout<<"1";
	else if(m1==5 && d1==31)
	cout<<"1";
	else if(m1==6 && d1==30)
	cout<<"1";
	else if(m1==7 && d1==31)
	cout<<"1";
	else if(m1==8 && d1==31)
	cout<<"1";
	else if(m1==9 &&d1==30)
	cout<<"1";
	else if(m1==10 && d1==31)
	cout<<"1";
	else if(m1==11 && d1==30)
	cout<<"1";
	else if(m1==12 && d1==31)
	cout<<"1";
	else 
	cout<<"0";
}