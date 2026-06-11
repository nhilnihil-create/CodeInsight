#include <bits/stdc++.h>
#include <stdio.h>
typedef long long int LL;
#define fr(i,p,n) for(LL i=p;i<n;i++)
#define fr1(i,p,n) for(LL i=p;i>=n;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define precise cout << std::setprecision(10) << std::fixed;

using namespace std;
 
int main()
{
    int a,b,c;
	int k;
 
	cin >> a >> b >> c;
	cin >> k;
 
	for(int i=0;i<k;i++){
		if(a>=b){
			b *= 2;
		}else if(b>=c){
			c *= 2;
		}else{
			c *= 2;
		}
	}
 
	if(a<b && b<c){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
 
    return 0;
}