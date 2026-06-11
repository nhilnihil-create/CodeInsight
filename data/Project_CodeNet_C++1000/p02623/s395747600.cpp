#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const char sp = ' ';

using namespace boost::multiprecision;
using namespace std;

ll N, M, K;
ll A[200000], B[200000];
ll deci=0;
bool can_clear(ll index){
    //cout<<deci<<sp<<index<<sp<<B[index]<<endl;
    return deci+B[index]<=K;
}

//条件に合致する最大indexを二分探索 O(logN)
//-2...全indexがみたす -1...条件に合致するものがない
ll nibutan_max(ll min, ll max){
  //評価関数can_clear(ll　value) を指定すること
  ll left=min, right=max;
  ll ans;
  while(true){
      //cout<<left<<" " <<right<<endl; //debug用
      if(left==right){
          if(can_clear(right)) return right;
          else return -1;
      }
      if(left+1==right){
        if(can_clear(right)){
          if(right==max) return max;
          else return right;
        }
        else{
          if(can_clear(left)) return left;
          else return -1;
        }
        break;
      }
      ll nibutan=(left+right)/2;
      bool can_do_it=can_clear(nibutan);
      if(can_do_it) left = nibutan;
      else right = nibutan;
  }
}



int main(void){
    cin>>N>>M>>K;

    rep(i, N){
        cin>>A[i];
        if(i!=0) A[i]+=A[i-1];
    }
    rep(i, M){
        cin>>B[i];
        if(i!=0) B[i]+=B[i-1];
    }
    ll Maxim=0;
    deci=0;
    Maxim=max(Maxim, nibutan_max(0,M-1)+1);
    rep(i, N){
        deci=A[i];
        if(deci>K) break;
        Maxim=max(Maxim, i+1+nibutan_max(0,M-1)+1);
    }
        cout<<Maxim<<endl;
    return 0;
}
