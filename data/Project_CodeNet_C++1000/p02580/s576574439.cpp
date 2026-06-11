//g++ -std=gnu++14 a.cpp

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
#include <stdio.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

ll MODP = 998244353;

int main(){
   int H,W,M;
   cin >> H >> W >> M;
   vector<int> I(H+1,0),J(W+1,0);
   vector<int> h(M),w(M);
   rep(i,M){
     cin >> h[i] >> w[i];
     I[h[i]]++;
     J[w[i]]++;
   }

   int maxinum = 0,maxjnum = 0;
   for(int i = 1;i <= H;i++){
     if(I[i] > maxinum){
       maxinum = I[i];
     }
   }
   for(int j = 1;j <= W;j++){
     if(J[j] > maxjnum){
       maxjnum = J[j];
     }
   }

   map<int,int> mi,mj;

   for(int i = 1;i <= H;i++){
     if(I[i] == maxinum){
       mi[i] = maxinum;
     }
   }
   for(int j = 1;j <= W;j++){
     if(maxjnum == J[j]){
       mj[j] = maxjnum;
     }
   }

   ll all = (mi.size())*(mj.size());

  rep(i,M){
    if(mi.count(h[i]) && mj.count(w[i])){
        all--;
      }
    }

  if(all){
    cout << maxinum + maxjnum << endl;
  }else{
    cout << maxinum + maxjnum - 1 << endl;
  }






}
