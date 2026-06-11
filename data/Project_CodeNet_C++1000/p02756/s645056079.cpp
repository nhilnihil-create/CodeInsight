#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  string S;
  ll Q;
  cin >> S;
  cin >> Q;
  vector<char> s;
  for(ll i=0;i<S.length();i++){
    s.push_back(S[i]);
  }
  ll T[Q];
  vector<ll> q(Q);
  vector<char> p(Q); 
  for(ll i=0;i<Q;i++){
    cin >> T[i];
    if(T[i]==1){
      q[i]=0;
    }else{
      cin >> q[i] >> p[i];
    }
  }
  bool flag = true;
  for(ll i=0;i<Q;i++){
    if(T[i]==1){
      flag = !flag;
    }else{
      if(flag){
	if(q[i]==2){
	  s.push_back(p[i]);
	}else{
	  s.insert(s.begin(),p[i]);
	}
      }else{
	if(q[i]==2){
	  s.insert(s.begin(),p[i]);
	}else{
	  s.push_back(p[i]);
	}	
      }
    }
  }
  if(flag){
    for(ll i=0;i<s.size();i++){
      cout << s[i];
    }
  }else{
    for(ll i=s.size()-1;i>=0;i--){
      cout << s[i];
    }
  }
  cout << endl;
}
