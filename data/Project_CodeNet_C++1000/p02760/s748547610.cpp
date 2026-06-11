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
  vector<vector<int>>A(3,vector<int>(3));
  vector<vector<int>>C(3,vector<int>(3,0));
  rep(i,3)rep(j,3)cin>>A[i][j];
  int N; cin>>N;
  vector<int>B(N);
  rep(i,N){
    cin>>B[i];
    rep(j,3)rep(k,3)if(A[j][k]==B[i])C[j][k]=1;
  }
  cout<<((C[0][0]==1&&C[0][1]==1&&C[0][2]==1)||(C[0][0]==1&&C[1][0]==1&&C[2][0]==1)||(C[0][0]==1&&C[1][1]==1&&C[2][2]==1)||(C[0][1]==1&&C[1][1]==1&&C[2][1]==1)||(C[0][2]==1&&C[1][2]==1&&C[2][2]==1)||(C[0][2]==1&&C[1][1]==1&&C[2][0]==1)||(C[1][0]==1&&C[1][1]==1&&C[1][2]==1)||(C[2][0]==1&&C[2][1]==1&&C[2][2]==1)? "Yes":"No")<<endl;
}