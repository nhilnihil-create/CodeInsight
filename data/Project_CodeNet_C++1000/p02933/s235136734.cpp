//
//  main.cpp
//  CoderProj
//
//  Created by Minoru Hayashi on 2020/03/12.
//  Copyright © 2020 Minoru Hayashi. All rights reserved.
//
//
//  
//

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i=0; i<(n); i++)
#define REP2(i,x,n) for (int i=x; i<(n); i++)
#define ALL(n) begin(n), end(n)

using ll = long long;

template<class T> inline bool chmin(T& a, T b){ if(a>b){a=b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b){ if(a<b){a=b; return 1;} return 0;}

// const ll INF = 1LL<<60;
// const int INF = 1<<29;
// const ll MOD = 1000000007;
// const double PI=3.1415926535897932;

//#define __DBG__


void solve(void){
  
  int a;
  string S;
 
  cin >> a >> S;
  
  if(a>=3200){
    cout << S << endl;
  }
  else
  {
  	cout << "red" << endl;
  }
  
  return;
   
}


int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
 
    return 0;
}



