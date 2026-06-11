#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pii;

const int N = 1e6 + 8 ;
int32_t main()
{
	int n ;
	cin >> n ;

	int have[N] ;
	int a[n] ;
	memset(have , 0 , sizeof(have)) ;

	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		a[i] = x ;
		have[x]++ ;
	}

	int ans = n ;

	for(int i = 0 ; i < n ; i++){
		int number = a[i] ;
		int fg = 0;
		for(int fact = 1 ; fact * fact <= number && !fg ; fact++){
			if(number % fact == 0){
				int f1 = fact , f2 = number / fact ;
				if(f1 != number && have[f1]){ans--; fg = 1 ;}
				else if(f1 == number && have[f1] > 1){ans--; fg = 1; }
				else if(f2 != number && have[f2]){ans-- ; fg = 1 ;}
				else if(f2 == number && have[f2] > 1){ans--; fg = 1;}
			}
		}
	}

	cout << ans <<" ";
	return 0;
}        