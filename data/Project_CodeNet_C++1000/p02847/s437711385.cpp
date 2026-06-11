#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main() {
  string s;
  cin>>s;
  if(s=="SUN") cout<<7<<endl;
  if(s=="MON") cout<<6<<endl;
  if(s=="TUE") cout<<5<<endl;
  if(s=="WED") cout<<4<<endl;
  if(s=="THU") cout<<3<<endl;
  if(s=="FRI") cout<<2<<endl;
  if(s=="SAT") cout<<1<<endl;
}