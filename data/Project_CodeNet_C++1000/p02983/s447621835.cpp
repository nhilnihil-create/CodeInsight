#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, int num=0){
  if(num == 0) num = (int)v.size();
  if(is_reverse) for(int i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<" ";}
  else for(int i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<" ";}
  cout << endl;
}

template <typename T>
void print_pairvec(const vector<T> &v, int num=0){
  if(num == 0) num = (int)v.size();
  cout << endl;
  for(int i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
}


template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

int main(){
  

  int L, R;
  cin >> L >> R;

  int MOD = 2019;
  vector<bool> vec(MOD, false);
  int length = min(MOD, R-L+1);
  for(int i=L; i<L+length; i++) vec[i%MOD]=true;

  int ans = 1e8+1;
  for(int i=0; i<MOD; i++){
    for(int j=i+1; j<MOD; j++){
      if(vec[i] & vec[j]) ans = min(ans, (i * j) %MOD);
    }
  }
  cout << ans << endl;
	return 0;
}

