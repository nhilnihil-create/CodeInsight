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
#define int long long
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define _GLIBCXX_DEBUG
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
	int N,K;
	cin>>N>>K;
    vector<bool>C(N+1);
	vector<int>d(K+1);
	vector<vector<int>>A(K+1,vector<int>(N+1,-1));
	vector<int>B(N+1);
	for(int i=1;i<=K;i++){
		cin>>d[i];
		rep(j,d[i]){
			cin>>A[i][j];
            C[A[i][j]]=true;
		}
	}
    int ans=0;
    for(int i=1;i<=N;i++){
        if(C[i]!=true)ans++;
    }
    cout<<ans<<endl;
}