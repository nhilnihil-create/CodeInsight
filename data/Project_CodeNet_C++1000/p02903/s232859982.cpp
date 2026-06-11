#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long int ll;
typedef vector<int >    vecint;
typedef vector<ll >      vecll;
typedef vector<double >   vecd;
typedef vector<string > vecstr;
typedef vector<bool >  vecbool;
typedef vector<vector<bool> >  vec2bool;
typedef vector<vector<int> >    vec2int;
typedef vector<vector<double> >   vec2d;
////////////////////////////////////////////////
int main()
{
  int h, w, a, b; cin >> h >> w >> a >>b;
  REP(i,h - b){
    REP(j,w){
      if(j < a){
	cout << 1;
      }else{
	cout << 0;
      }
    }
    cout << endl;
  }
  REP(i,b){
    REP(j,w){
      if(j < a){
	cout << 0;
      }else{
	cout << 1;
      }
    }
    cout << endl;
  }
}
