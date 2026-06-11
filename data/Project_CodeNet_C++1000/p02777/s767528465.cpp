#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
 
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

int main()
{
  string S,T,U;
  int A,B;
  cin>>S>>T;
  cin>>A>>B>>U;
  
  if (U==S) cout<<A-1<<" "<<B<<endl;
  else cout<<A<<" "<<B-1<<endl;
}