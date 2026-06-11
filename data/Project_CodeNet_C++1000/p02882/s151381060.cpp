#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  double a, b, x;
  cin>>a>>b>>x;
  double theta;
  if(a*a*b<2*x) {
    theta = atan(2*(a*a*b-x)/(a*a*a));
    theta *= 180/PI;
  }
  else {
    theta = atan(a*b*b/(2*x));
    theta *= 180/PI;
  }
  cout<<setprecision(20)<<theta<<endl;
}

