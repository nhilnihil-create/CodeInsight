#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;
#define _GLIBCXX_DEBUG
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<char> cvec;
typedef vector<double> dvec;
typedef pair<ll, ll> LP;
typedef tuple<ll, ll, ll> LT;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define fs first
#define sc second
int main()	{
  string s;
  cin>>s;
  int d;
  if(s=="SUN") d=0;
  if(s=="MON") d=1;
  if(s=="TUE") d=2;
  if(s=="WED") d=3;
  if(s=="THU") d=4;
  if(s=="FRI") d=5;
  if(s=="SAT") d=6;
  cout<<7-d<<endl;
}