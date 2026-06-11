#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define ArraySizeOf(array)     (sizeof(array) / sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define _GLIBCXX_DEBUG
#define int long long
int INF = 1e9+7;
unsigned NthDayOfWeekToDay(unsigned n, unsigned dow, unsigned dow1)
{
unsigned day;
if(dow < dow1) dow += 7;
day = dow - dow1;
day += 7 * n - 6;
return day;
}
unsigned DayToWeekNumber(unsigned day)
{
  return (day - 1) / 7 + 1;
}
unsigned AnotherDayOfWeek(unsigned day, unsigned day0, unsigned dow0)
{
  return (dow0 + 35 + day - day0) % 7;
}
using namespace std;
signed main(){
	int N,M; cin>>N>>M;
	int H[N+1];
	REP(i,N+1)cin>>H[i];
	int A[M];
	int B[M];
	vector<int>C(N+1);
	rep(i,M){
		cin>>A[i]>>B[i];
		if(H[A[i]]<=H[B[i]])C[A[i]]=1;
		if(H[A[i]]>=H[B[i]])C[B[i]]=1;
	}
	int ans=0;
	REP(i,N+1)if(C[i]==0)ans++;
	cout<<ans<<endl;
}