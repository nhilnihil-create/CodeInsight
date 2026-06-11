/*input
4
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

int countDivisors(int n) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 



int main() {
 	int64 n;
 	cin>>n;
 	int64 arr[n+1];
 	memset(arr,0,sizeof(arr));
 	for(int64 i = 1; i<n+1;i++){
 		int64 j = 0;
 		while(j<n+1){
 			arr[j]++;
 			j+=i;
 		}
 	}
 	int64 ans = 0;
 	rep(i,n+1){
 		ans+=i*arr[i];
 	}
 	cout<<ans<<endl;

}



 
