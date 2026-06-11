#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
int e[1048576],o[1048576];
int main(void)
{
  REP(i,1048576) e[i]=1048576;
  REP(i,1048576) o[i]=1048576;
  e[0]=0;
  o[0]=0;
  REP(i,1024){
    int gap=i*(i+1)*(i+2)/6;
    for(int j=0;j+gap<1048576;++j) e[j+gap]=min(e[j+gap],e[j]+1);
    if(gap%2==1) for(int j=0;j+gap<1048576;++j) o[j+gap]=min(o[j+gap],o[j]+1);
  }    
  for(;;){
    int n;
    cin >> n;
    if(!n) return 0;
    cout << e[n] << ' ' << o[n] << endl;
  }
}