#include <bits/stdc++.h>

typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define DECIM8  fixed<<setprecision(8) 
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

using namespace std;
string s;
int c=0;
bool balance(void){
  if(c<SZ(s) && s[c]=='('){
    ++c;
    bool flag=balance();
    if(c<SZ(s) && s[c]==')'){
      ++c;
      return flag&&balance();
    }
    else return false;
  }
  if(c<SZ(s) && s[c]=='['){
    ++c;
    bool flag=balance();
    if(c<SZ(s) && s[c]==']'){
      ++c;
      return flag&&balance();
    }
    else return false;
  }
  if(c<SZ(s) && s[c]!='(' && s[c]!=')' && s[c]!='[' && s[c]!=']'){
    ++c;
    return balance();
  }
  return true;
}
int main(void)
{
  for(;;){
    getline(cin,s);
    if(s==".") return 0;
    c=0;
    if(balance()&&c==SZ(s)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}