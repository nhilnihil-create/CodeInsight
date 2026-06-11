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
	int A,B,M; cin>>A>>B>>M;
	vector<int> a(A);
	vector<int> b(B);
	rep(i,A)cin>>a[i];
	rep(i,B)cin>>b[i];
	int x[M];
	int y[M];
	int c[M];
	vector<int> d(M+1);
	rep(i,M){
		cin>>x[i]>>y[i]>>c[i];
		d[i]=a[x[i]-1]+b[y[i]-1]-c[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	d[M]=a[0]+b[0];
	sort(d.begin(),d.end());
	cout<<d[0]<<endl;
}