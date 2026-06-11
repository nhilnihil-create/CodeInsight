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

ll A[300000];

ll N, K;

bool can_clear(ll index){
    ll sum=0;
    rep(i, N){
        sum+=max((A[i]-1)/index, (ll)0);
        //cout<<A[i]<<sp<<max((A[i]-1)/index, (ll)0)<<endl;
    }
    //cout<<endl;
    return (sum<=K);
}
//条件に合致する最小indexを二分探索 O(logN)
//1...全indexがみたす -1...条件に合致するものがない
ll nibutan_min(ll min, ll max){
  //評価関数can_clear(ll　value) を指定すること
  ll left=min, right=max;
  while(true){
      //cout<<left<<" " <<right<<endl; //debug用
      if(left+1==right){
        if(can_clear(left)){
          if(left==min) return 1;
          else return left;
        }
        else{
          if(can_clear(right)) return right;
          else return -1;
        }
        break;
      }
      ll nibutan=(left+right)/2;
      bool can_do_it=can_clear(nibutan);
      if(can_do_it) right = nibutan;
      else left = nibutan;
  }
}


int main(void){
    cin>>N>>K;
    rep(i, N) cin>>A[i];
    cout<<nibutan_min(1, 1000000000)<<endl;
    return 0;
}
