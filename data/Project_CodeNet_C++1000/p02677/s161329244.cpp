#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) (int)x.size()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fill(a,v) memset(a,v,sizeof(a))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define INF 0x3f3f3f3f//infinity for integers
#define JJ ios_base::sync_with_stdio(0); cin.tie(0)//input fast
#define MOD 1000000007
#define hash(n) unordered_map<int,int>mp(n)
#define pi (double)3.141592653589793238
bool comp(int a, int b){
	return a>b;
}

int main() 
{ 
	JJ;
	double a,b,h,m; cin>>a>>b>>h>>m;
	h=h*5+(m/12);
	double angle=((h-m)*pi)/30;
	double c=a*a + b*b - (2*a*b*cos(angle));
	cout<<fixed<<setprecision(20)<<sqrt(c)<<endl;





	return 0;



    
} 