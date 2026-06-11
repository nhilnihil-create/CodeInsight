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
#define REV(i,n) for(int i=n-1;i>0;i--)
#define _GLIBCXX_DEBUG
int INF = 1e9 + 7;
unsigned NthDayOfWeekToDay(unsigned n, unsigned dow, unsigned dow1)
{
    unsigned day;
    if (dow < dow1) dow += 7;
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
signed main() {
  int N; cin>>N;
  vector<int>p(N);
  vector<int>q(N);
  rep(i,N)cin>>p[i];
  rep(i,N){
    rep(j,N)q[i]=p[i];
    rep(j,N){
      rep(k,N){
        if(i==k)q[k]=p[j];
        else if(j==k)q[k]=p[i];
        else q[k]=p[k];
      }
      REP(k,N){
        if(q[k]<=q[k-1])break;
        if(k==N-1){
          cout<<"YES"<<endl;
          return 0;
        }
      }
    }
  }
  cout<<"NO"<<endl;
}