#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
using namespace std;

#define REP(i, n) for(int i=0;i<(n);i++)

#define MAX_N 53
#define MAX_R 53

int p[MAX_R], c[MAX_R];
int card [MAX_N][2];
int n,r;

bool input(){
  cin>>n>>r;
  REP(i, r)cin>>p[i]>>c[i];
  return (n!=0);
}

void solve(){
    REP(i, n+1)card[i][0] = i;
    REP(i, n+1)card[i][1] = i;

    REP(i, r) {
      //REP(j, n)cout<<card[n-j][0]<<' ';
      //cout<<endl;
      REP(j, c[i]) {
        card[n-j][1] = card[n-p[i]+1-j][0];
      }

      REP(j, p[i]-1) {
        card[n-c[i]-j][1] = card[n-j][0];
      }

     // REP(j, n-c[i]-p[i])card[j+1][1] = card[j+1][0];

      REP(i, n)card[i+1][0] = card[i+1][1];
    }

    //REP(i, n)cout<<card[n-i][0]<<' ';
    cout<<card[n][0]<<endl;
}

int main (){
  while(input()){
    solve();
  }
  return 0;
}