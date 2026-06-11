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
  string s;
  cin >> s;
  int N = s.size();
  vector<int> to_inv(N, 0);// to_inv[i]: s[i]から逆の文字似た取り付くまでの距離
  // char prev='L';// s[0]は必ずRなので Lを入れとく
  int cnt = 0;
  for(int i=0; i<N; i++){// s[i]がRのときだけ考える
    if(s[i] == 'L') cnt = 0;
    else{
      if(cnt) to_inv[i] = to_inv[i-1]-1;
      else{
        int j = i;
        while(s[j] == 'R'){cnt++; j++;}
        to_inv[i] = cnt;
      }
    }
  }

  // cout << " to_inv: " ;  print_vec(to_inv);
  cnt = 0;
  for(int i=N-1; i>=0; i--){// s[i]がLの時だけ考える
    if(s[i] == 'R') cnt = 0;
    else{
      if(cnt) to_inv[i] = to_inv[i+1] - 1;
      else{
        int j=i;
        while(s[j] == 'L'){cnt++; j--;}
        to_inv[i] = cnt;
      }
    }
  }

  // cout << " to_inv: " ;  print_vec(to_inv);
  vector<int> ans(N, 0);
  for(int i=0; i<N; i++){
    if(s[i] == 'R'){
      if(to_inv[i]%2 == 0) ans[i+to_inv[i]]++;
      else ans[i+to_inv[i]-1]++;
    }
    else{
      if(to_inv[i]%2 == 0) ans[i-to_inv[i]]++;
      else ans[i-to_inv[i]+1]++;
    }
    // cout << " i: "<< i << " s[i]: " << s[i] << " to_inv[i]: " << to_inv[i] << endl;
  }

  for(int i=0; i<N; i++) cout << ans[i] << " ";
  cout << endl;
	return 0;
}

