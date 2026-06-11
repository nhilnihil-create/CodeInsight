#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;
 
#define ll long long
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back 
#define pii pair<int,int>
#define mp make_pair
#define pi 3.14159265359
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
 
int main(){
  while(1){
	int x,y,s;
	cin >> x >> y >> s;
	if(x==0&&y==0&&s==0) break;

	int now = 0;
	int mae;
	int ato;

	REP(i,s){
	  REP(j,s){
		if(i==0||j==0) continue;
		mae = (i*(100+x))/100+(j*(100+x))/100;
		ato = (i*(100+y))/100+(j*(100+y))/100;

		if(mae==s && ato > now) now = ato;
		  //		  cout << i <<" " << j <<endl;}
	  }
	}
	cout << now << endl;
  }
}