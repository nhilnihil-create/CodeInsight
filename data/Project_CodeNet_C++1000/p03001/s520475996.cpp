#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<iterator>
#include<cmath>
#include<string>
#include<algorithm>
#include<sstream>
#include<queue>
#include<list>
#include<deque>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<chrono>
#include<iomanip>

/*  auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(stop - start);
pr(duration.count());    */


#define FastIO      ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define pb          push_back
#define siz         100009
#define mp          make_pair
#define ll          long long int
#define fileout     freopen("output.txt","w",stdout)
#define filein      freopen("input.txt","r",stdin)
#define pi          acos(-1.0)
#define all(x)      x.begin(),x.end()
#define ull		    unsigned long long int
#define m(a)	    memset(a,0,sizeof(a))
#define f(i,n)	    for(ll i=0;i<n;i++)
#define sc(a)	    scanf("%lld",&a)
#define pr(a)	    printf("%lld\n",a)
#define vll			vector<ll>
#define sll			set<ll>
const ll inf = 1000000000000000;
ll in = 1000000000000000000;
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

int main()
{
	FastIO;
	double t, a, i, j, k, q, c, d, b, r,n;
	cin >> a >> b >> c >> d;
	if(a/2.0==c && b/2.0==d)
		cout << setprecision(10) << fixed << .5 * a * b <<" 1"<< endl;
	else
		cout << setprecision(10) << fixed << .5 * a * b << " 0" << endl;
	return 0;
}
