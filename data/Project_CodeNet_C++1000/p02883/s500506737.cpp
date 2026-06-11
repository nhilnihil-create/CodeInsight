#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
typedef long long int ll;
int main(void){
  ll N,K;
  cin >> N >> K;
  vector<ll> A,F;

  for(int i=0;i<N;i++){
    ll tmp;
    cin >> tmp;
    A.push_back(tmp);
  }

  for(int i=0;i<N;i++){
    ll tmp;
    cin >> tmp;
    F.push_back(tmp);
  }
  sort(A.begin(),A.end());
  sort(F.begin(),F.end(),greater<ll>());

  ll max = 0;
  ll sumA = 0;
  for(int i=0;i<A.size();i++){
    ll tmp = A[i]*F[i];
    sumA = sumA + A[i];
    if(max < tmp){
      max = tmp;
    }
  }
  if(sumA <= K){
    cout << 0 << endl;
    return 0;
  }
  //0にできない場合二分探索
  ll l,r;
  l=0;
  r=max;
  while(r-l>1){
    ll c = (r+l)/2;
    // cは達成できるか？
    bool flag = true;
    ll sum = 0;
    for(int i=0;i<A.size();i++){
      ll k = ceil(A[i] - c/(double)F[i]);
      if(k<0)
	k=0;
      sum = sum + k;
      if(sum > K){
        flag = false;
        break;
      }
    }
    //cout << r << " " << l << " " << c << endl;
    if(flag){
      r = c;
    }else{
      l = c;
    }
  }
  cout << r << endl;
  return 0;
}
