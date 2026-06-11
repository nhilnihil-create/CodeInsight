#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
using namespace std;
using ll = long long;

const ll p=1e9+7;

int main(){
  string S;
  cin >> S;
  int N=S.size();
  int r=0;
  int k=1;
  vector<int> que;
  for(int i=0;i<N;i++){
    if(S[N-i-1]!='?'){
      r=((S[N-i-1]-'0')*k+r)%13;
    }
    else{
      que.push_back(k);
    }
    k=k*10%13;
  }
  int M=que.size();
  vector<ll> num(13,0);
  num[r]++;
  for(int i=0;i<M;i++){
    int q=que[i];
    vector<ll> curnum(13,0);
    for(int j=0;j<13;j++){
      if(num[j]==0){
        continue;
      }
      for(int k=0;k<=9;k++){
        curnum[(j+q*k)%13]=(curnum[(j+q*k)%13]+num[j])%p;
      }
    }
    for(int j=0;j<13;j++){
      num[j]=(curnum[j])%p;
    }
  }
  cout << num[5] << endl;
}