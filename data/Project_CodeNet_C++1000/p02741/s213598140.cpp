#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define f first
#define s second
#define mk make_pair
#define MOD 1000000007
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	ll a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	ll n;
	cin>>n;
	cout<<a[n-1];
  return 0;
}
