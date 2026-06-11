#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> plus(0);
  vector<int64_t> minus(0);
  for(int i=0; i<N; i++){
    int64_t x;
    cin >> x;
    if(x > 0){
      plus.push_back(x);
    }
    else{
      minus.push_back(x);
    }
  }
  
  sort(plus.begin(),plus.end());
  sort(minus.begin(),minus.end());
  
  int64_t num = 0;
  vector<pair<int64_t,int64_t>> ans(0);
  pair<int64_t,int64_t> P;
  
  if(plus.size() > 0 && minus.size() > 0){
    int64_t a = minus.at(0);
    for(int i=0; i<plus.size()-1; i++){
      P = make_pair(a,plus.at(i));
      ans.push_back(P);
      a -= plus.at(i);
    }
    int64_t b = plus.at(plus.size()-1);
    for(int i=1; i<minus.size(); i++){
      P = make_pair(b,minus.at(i));
      ans.push_back(P);
      b -= minus.at(i);
    }
    P = make_pair(b,a);
    ans.push_back(P);
    num = b-a;
  }
  else if(plus.size() > 1){
    int64_t a = plus.at(0);
    for(int i=1; i<plus.size()-1; i++){
      P = make_pair(a,plus.at(i));
      ans.push_back(P);
      a -= plus.at(i);
    }
    P = make_pair(plus.at(plus.size()-1),a);
    ans.push_back(P);
    num = plus.at(plus.size()-1)-a;
  }
  else if(minus.size() > 1){
    int64_t a = minus.at(minus.size()-1);
    for(int i=minus.size()-2; i>=0; i--){
      P = make_pair(a,minus.at(i));
      ans.push_back(P);
      a -= minus.at(i);
    }
    num = a;
  }
  else if(plus.size() == 1){
    num = plus.at(0);
  }
  else if(minus.size() == 1){
    num = minus.at(0);
  }

  
  cout << num << endl;
  for(int i=0; i<ans.size(); i++){
    P = ans.at(i);
    int64_t p = P.first;
    int64_t q = P.second;
    cout << p << " " << q << endl;
  }
    
}   