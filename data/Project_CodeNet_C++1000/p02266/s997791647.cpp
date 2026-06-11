#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

#define ll long long

int main(){
  string s;
  cin >> s;
  ll n = s.length();
  vector< pair<ll,ll> > v;
  stack<ll> st;
  for(ll i = 0; i < n; i++){
    if(s[i] == '/'){
      if(st.size()){
	v.push_back(make_pair(st.top(),i));
	st.pop();
      }
    }else if(s[i] == '_'){

    }else{
      st.push(i);
    }
  }

  sort(v.begin(),v.end());

  list<ll> ans;
  ll sum = 0;
  {
    vector< pair<ll,ll> > :: iterator it = v.begin();

    while(it != v.end()){
      ll ps = 0;
      ll e = (*it).second;
      while(it != v.end() && (*it).first < e){
	ps += (*it).second - (*it).first;
	it++;
      }
      sum += ps;
      ans.push_back(ps);
    }

  }
  cout << sum << '\n';
  cout << ans.size();
  for(list<ll>::iterator it = ans.begin(); it != ans.end(); it++){
    cout << ' ' << *it;
  }
  cout << '\n';
}