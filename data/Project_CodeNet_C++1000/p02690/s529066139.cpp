/*input
667763461
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
#define MAXN   100001  
 

std::vector<int> ans;

void factorize(long long n){
   
   int count = 0;
   while (!(n % 2)) {
      n/= 2;
      count++;
   }
   if (count)
      ans.push_back(count);
   for (long long i = 3; i <= sqrt(n); i += 2) {
      count = 0;
      while (n % i == 0) {
         count++;
         n = n / i;
      }
      if (count)
      	ans.push_back(count);
   }
   if (n > 2)
   	ans.push_back(1);
}






int main() {
 	int64 n;
 	cin>>n;
 	int64 g = floor(pow(n,.2));
 	int a = 0;
 	int b = 0;

 	for(int64 i = -2*g; i<=2*g;i++){
 		int64 p = pow(i,5);
 		int64 q = abs(p-n);


 		if(pow(floor(pow(q,.2)),5)==q){
 			a=i;
 			b = pow(q,.2);
 		}
 	}
 	if(pow(a,5)-pow(b,5)==n){
 		cout<<a<<" "<<b<<endl;
 	}
 	else{
 		b = -1*b;
 		cout<<a<<" "<<b<<endl;
 	}
 	
}



 
