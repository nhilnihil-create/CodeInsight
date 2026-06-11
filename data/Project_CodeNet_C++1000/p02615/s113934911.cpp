/*input
7
1 1 1 1 1 1 1
*/
 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <tgmath.h>
 
using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define ar array
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define tests int r; cin >> r; while(r--)
#define MP make_pair
#define PI acos(-1)
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define godspeed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
 
#define M(x) ((x)%(1000000007))
 

int arr[1010][1010];

int h;
int w;



bool legal(int x, int y){
	if(x>=1&&x<=h){
		if(y>=1&&y<=w){
			if(arr[x][y]){
				return true;

			}
		}
	}
	return false;
}


int main() {
 	int n;
 	cin>>n;
 	if(n<2){
 		cout<<0<<endl;
 	}
 	else{
		int64 arr[n];
		priority_queue<int64> s;
		rep(i,n){
			int64 a;
			cin>>a;
			arr[i] = a;
		}
		sort(arr,arr+n);
		s.push(arr[n-1]);
		int64 j = n-2;
		int64 ans = 0;
		while(j>=0){
			int64 a = arr[j];
			ans = ans + s.top();
			s.pop();
			s.push(a);
			s.push(a);
			j--;
		}
		cout<<ans<<endl;
 	}
 	


 	
}



 
