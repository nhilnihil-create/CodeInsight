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
int notprime[345678]={};
int main(void)
{
  for(;;){
    int n;
    cin >> n;
    if(!n) return 0;
    notprime[0]=1;
    notprime[1]=1;
    REP(i,500){
      if(notprime[i]) continue;
      for(int j=i*i;j<250000;j+=i)
	notprime[j]=1;
    }
    int answer=0;
    FOR(i,n+1,n*2+1)
      if(!notprime[i]) answer++;
    cout << answer << endl;
  }
}