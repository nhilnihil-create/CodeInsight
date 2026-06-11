// #include <iostream>
// #include <vector>
// #include <array>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>

// using namespace std;
// typedef long long ll;

// int main(){
//     ll n;
//     cin >> n;
//     vector<array<double, 3>> p;
//     for(int i = 0; i < n; ++i){
//         double x, y;
//         cin >> x >> y;
//         if(x == 0 && y == 0){ continue; }
//         array<double, 3> tmp;
//         tmp.at(0) = atan2(y, x);
//         tmp.at(1) = x;
//         tmp.at(2) = y;
//         p.push_back(tmp);
//     }
//     sort(p.begin(), p.end());

//     double ans = 0;
//     for(int i = 0; i < p.size(); ++i)
// 	{
//         double x = 0, y = 0;
//         for(int j = 0; j < p.size(); ++j)
// 		{
// 			// cout<<(i+j)%p.size()<<' ';
//             x += p.at((i + j) % p.size()).at(1);
//             y += p.at((i + j) % p.size()).at(2);
//             ans = max(ans, sqrt(x * x + y * y));
// 			// cout<<x<<' '<<y<<'\n';
//         }
// 		// cout<<'\n';
//     }
//     printf("%.20f\n", ans);
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define rep(i,j,n) for(int i=j; i<n; i++)
#define INF 1000000000000000000 // If you use it, make sure not to put in "int" type variable ;(, use long long int
void optimizeIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
const ll mod=1000000007;

int main()
{
    optimizeIO();
    int nT; nT=1;
	while(nT--)
	{
		ll n; cin>>n;
		array<double,3>a[n];
		rep(i,0,n) { double x,y; cin>>x>>y; a[i]={atan2(y,x),x,y}; }
		sort(a,a+n);
		double dp[n];
		dp[0]=a[0][1]*a[0][1]+a[0][2]*a[0][2];
		double ans=0;
		for(int i = 0; i < n; ++i)
		{
			double x = 0, y = 0;
			for(int j = 0; j < n; ++j)
			{
				// cout<<(i+j)%p.size()<<' ';
				x += a[((i + j) % n)].at(1);
				y += a[((i + j) % n)].at(2);
				ans = max(ans, sqrt(x * x + y * y));
				// cout<<x<<' '<<y<<'\n';
			}
			// cout<<'\n';
		}
		printf("%.20f\n", ans);
	}
	return 0;
}


// https://atcoder.jp/contests/abc139/submissions/7294031
