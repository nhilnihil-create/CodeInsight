#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cstdint>

using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using namespace std;

vector<int> create_primes(){
  char is_prime[1001] = {0};
  for(int i = 2; i < 1001; i++){
    is_prime[i] = 1;
  }
  for(int i = 2; i < 1001; i++){
    if (is_prime[i]){
      for (int j = 2; j * i < 1001; j++){
        is_prime[i*j] = 0;
      }
    }
  }
  vector<int> primes;
  for(int i = 2; i < 1001; i++){
    if(is_prime[i]){
      primes.push_back(i);
    }
  }
  return primes;
}
vector<int> primes = create_primes();
vector<int> factorize(int a){
 vector<int> f;
 for(auto p: primes){
   //cout<<p<<endl;
  if (a % p == 0){
    f.push_back(p);
    while( a % p == 0) a /= p;
  }
  if(p*p > a){
    if(a>1) f.push_back(a);
    //cout << a <<'a'<<endl;
    break;
  }
 }
 return f;
}

int main()
{
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0 ; i< n; i++){
    cin >> A[i];
  }
  bool pw = true;
  set<int> common;
  set<int> all;
  bool first = true;
  for(auto a: A){
    auto f = factorize(a);
    auto fs = set(f.begin(), f.end());
    int pre_size = all.size();
    vector<int> tmp;
    set_intersection(
      common.begin(), common.end(),
      fs.begin(), fs.end(), 
      std::back_inserter(tmp));
    common = set(tmp.begin(), tmp.end());
    all.insert(f.begin(), f.end());
    if(!first && all.size() < pre_size + f.size()){
      pw = false;
    }
    if (first){
      common = set(f.begin(), f.end());
    }
    first=false;
    /*cout << a<<':';
    for(auto c:f) cout <<c << ',';
    cout<<':';
    for(auto c:common) cout <<c << ',';
    cout<<':';
    for(auto c:all) cout <<c << ',';
    cout<<endl;*/
  }
  if (pw){
    cout << "pairwise coprime";
  }else if(common.size()==0){
    cout << "setwise coprime";
  }else{
    cout << "not coprime";
  }
}
