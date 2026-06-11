#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define ull unsigned long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define FOR(i,start,stop)  for(int i=(start); i < (stop); i++)
#define FORD(i,start,stop) for(int i=(start); i >= (stop); i--)
#define RIP(i,stop) FOR(i,0,stop)
#define PI 3.141592653589793
#define PRECISION(c,f) fixed << setprecision(c) << f
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N, M; 
  cin >> N >> M;

  vector<int> a(N);
  ll sum=0;
  RIP(i,N) {cin >> a[i]; sum += a[i];}

  sort(a.begin(), a.end(), greater<int>());

  double d;
  d = sum / (4.0*M);

  if(d <= a[M-1]) yes;
  else no;

  return 0;
}
