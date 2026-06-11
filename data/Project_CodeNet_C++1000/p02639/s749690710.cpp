#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pii;

int32_t main()
{
	int a[5] ;
	for(int i = 0 ; i < 5 ; i++)
	{
		cin >> a[i] ;

		if(a[i] == 0){
			cout << i + 1 ;
			return 0 ;
		}
	}
	return 0;
}        