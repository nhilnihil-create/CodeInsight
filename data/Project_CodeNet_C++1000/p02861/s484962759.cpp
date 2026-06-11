#include <bits/stdc++.h>
 
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define hello777 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#include <string>
#define pie 3.14159265358979323846
constexpr int MOD = 1e9+7;
const int N= 50000;
using namespace std;


ll gcd(int a, int b)
{ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
 
ll lcm(int a, int b)  
 {  
    return a/gcd(a, b) *b;  
 }
  
int prime(int n)
{
	rep(i,2,n+1)
	{
		if(n%i==0)return i;
	}
	
}


void solve() 
{
int n, cnt = 0;
	cin >> n;
	double dist = 0;
	vector<int> id(n);
	vector<double> x(n), y(n);
	rep (i,0, n) cin >> x[i] >> y[i], id[i] = i;
	do {
	  rep (i,0, n - 1) {
		double p = (x[id[i]] - x[id[i + 1]]) * (x[id[i]] - x[id[i + 1]]) + (y[id[i]] - y[id[i + 1]]) * (y[id[i]] - y[id[i + 1]]);
		dist += sqrt(p);
	  }
	  cnt++;
	} while (next_permutation(id.begin(), id.end()));
	cout << fixed << setprecision(10) << dist / cnt << endl;

}

int main()
{
	hello777;
	int q=1;
//    cin>>q;
    while(q--)
    {   
      solve();
    }
}