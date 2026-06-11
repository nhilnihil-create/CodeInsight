#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl; cout << "i=  ";for(ll i=0; i<num; i++) cout << i << "   ";cout << endl;  
  cout << "    ";
  if(is_reverse) for(ll i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<"   ";}
  else for(ll i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<"   ";}
  cout << endl;
}

// template <typename T>
// void print_pairvec(const vector<T> &v, ll num=0){
//   if(num == 0) num = (ll)v.size();
//   cout << endl; for(ll i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
// }
template <typename T>
void print_pairvec(const T &_pair, ll num=0){
  cout << endl; for(pair<ll, int> x: _pair){ cout << x.first << " " << x.second << endl;}
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
  cout << endl; cout << "       ";
  for(ll i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(ll i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(ll j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

int main(){
  string s, t;
  cin >> s >> t;
  map<char, int> s_mp, t_mp;
  for(int i=0; i<(int)s.size(); i++) s_mp[s[i]]++;
  for(int i=0; i<(int)t.size(); i++) t_mp[t[i]]++;
  
  for(int i=0; i<(int)t.size(); i++){
    if(s_mp[t[i]] == 0){
      cout << "-1" << endl;
      return 0;
    }
  }

  vector<vector<ll>> vec(26);
  for(int i=0; i<(int)s.size(); i++) vec[s[i]-'a'].push_back((i+1));
  for(int i=0; i<(int)s.size(); i++) vec[s[i]-'a'].push_back((i+1)+(int)s.size());//2周分つける
  
  ll ans = 0;
  ll place = 0;
  ll cnt = 0;
  for(int i=0; i<(int)t.size(); i++){
    int c = t[i] - 'a';
    place = *lower_bound(vec[c].begin(), vec[c].end(), place+1);

    // cout << " vec[" << t[i] << "]: "; print_vec(vec[c]);
    // cout << " ans: " << ans << " t[i]: " << t[i] << " c: " << c << " place: " << place << endl;
    if(place > (int)s.size()){
      place -= (int)s.size();
      cnt++;
      // cout << " yah " << endl;
    }
    ans = place + (int)s.size() * cnt;
  }
  cout << ans << endl;
  return 0;
}
