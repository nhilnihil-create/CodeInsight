/*input
5
24 11 8 3 16
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
 	int arr[n];
 	map<int,int> mp;
 	rep(i,n){
 		int a;
 		cin>>a;
 		arr[i] = a;
 		mp[a]++;
 	}
 	if(mp[1]>1){
 		cout<<0<<endl;
 	}
 	else if(mp[1]==1){
 		cout<<1<<endl;
 	}
 	else{
 		int count = n;
 		sort(arr,arr+n);
 		rep(i,n){
 			int a = arr[i];
 			if(mp[a]>1){
 				count--;
 			}
 			else{
 				for(int j = 2; j<=sqrt(a);j++){

 					if(a%j==0){
 						

 						if(mp.find(j)!=mp.end()||mp.find(a/j)!=mp.end()){
 							count--;
 							break;
 						}
 					}
 				}
 			}
 		}
 		cout<<count<<endl;
 	}

}



 
