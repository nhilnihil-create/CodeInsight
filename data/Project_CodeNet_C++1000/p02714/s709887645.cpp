#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ar;
  ll res=0;
  ll r_counter=0;
  ll g_counter=0;
  ll b_counter=0;
  for(ll i=0;i<s.length();i++){
  	if(s[i]=='R'){
      ar.push_back(0);
      r_counter++;
    }
    else if(s[i]=='G'){
      ar.push_back(1);
      g_counter++;
    }else if(s[i]=='B'){
      ar.push_back(2);
      b_counter++;
    }
  }

	res=r_counter*g_counter*b_counter;
  
  for(ll i=0;i<ar.size();i++){
  	for(ll k=i+1;k<ar.size();k++){
      if(k-i+k>=ar.size())continue;
    	if(((ar[i]!=ar[k])&&(ar[k]!=ar[k-i+k]))&&(ar[i]!=ar[k-i+k])){
          res--;
    }
  }
  }
  cout << res << endl;
}