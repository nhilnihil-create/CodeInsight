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
using namespace std;
using ll = long long;

int N,K;
vector<int> A;

bool C(int x){
  ll count=0;
  for(int i=0;i<N;i++){
    count+=(A[i]+x-1)/x-1;
  }
  return (count<=K);
}

int main(){
  cin >> N >> K;
  A.resize(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int left=0,right=1e9;
  while(right-left>1){
    int mid=(left+right)/2;
    if(C(mid)){
      right=mid;
    }
    else{
      left=mid;
    }
  }
  cout << right << endl;
}