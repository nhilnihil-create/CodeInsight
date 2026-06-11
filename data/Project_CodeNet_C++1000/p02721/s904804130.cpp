#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
 
using namespace std;
typedef long long ll;

int f(vector<int> &a, const string &s, int N, int C){
  int l=-C-10;
  for(int i=0;i<N;i++){
    if(s[i]=='o' & l+C<i){
      l=i; a[i]=1;
    }
  }
  return 0;
}


int main(){
  int N,K,C;
  cin >> N >> K >> C;
  string s;
  cin >> s;
  vector<int> a(N,0);
  vector<int> b(N,0);

  f(a,s,N,C);
  int sum;
  sum=accumulate(a.begin(),a.end(),0);
  if(K<sum){
    cout << endl;
    return 0;
  }
  reverse(s.begin(),s.end());
  f(b,s,N,C);
  reverse(b.begin(),b.end());
  for(int i=0;i<N;i++){
    if(a[i]==1 & b[i]==1){
      cout << i+1 << endl;
    }
  }
  
  return 0;
}