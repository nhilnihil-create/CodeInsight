#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define inf 1000000000
#define mod 1000000007

ll power(ll a, ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a);
        a = (a*a);
        b >>= 1;
    }
    return prod;
}
bool comp(pair<int,int> a , pair<int,int> b)
{
		if(a.ff != b.ff)
			return a.ff < b.ff;
		return a.ss > b.ss;
}
int main(){

	int n;
	cin >> n;
	pair<string , int> p[n];
	map<string ,int> m;
	int arr[n] = {0};
	for(int i = 0 ; i < n ;i++)
	{
		cin >> p[i].ff >> p[i].ss;
		m[p[i].ff] = i;
	}
	arr[0] = p[0].ss;
	for(int i = 1 ; i < n ; i++)
	{
		arr[i] = arr[i-1] + p[i].ss;
	}
	string s;
	cin >> s;
	cout << arr[n-1] - arr[m[s]];
 	return 0;
}


