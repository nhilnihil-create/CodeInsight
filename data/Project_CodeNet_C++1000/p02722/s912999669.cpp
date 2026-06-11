#include <bits/stdc++.h>
#define mod 1000000007
 
using namespace std;

vector<long long> divisor(long long n){
  vector<long long> ret;
  for(long long i=1; i*i<=n; i++){
    if(n%i == 0){
      ret.push_back(i);
      if(i*i != n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main(){
  long long N;
  cin >> N;
  long long i;
  vector<long long> notDiv = divisor(N-1);
  vector<long long> Div = divisor(N);
  int DivNum = Div.size();
  long long tmp,yaku;
  long long divCount = 0;
  for(i=1; i<DivNum; i++){
    yaku = Div.at(i);
    tmp=N;
    while(tmp%yaku == 0){
      tmp /= yaku;
    }
    if(tmp%yaku == 1) divCount++;
  }
  cout << notDiv.size() + divCount-1;
  return 0;
}