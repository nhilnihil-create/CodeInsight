#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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
  for(int i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
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

using P = pair<double, double>;

const double ROOT3_half = 0.8660254038;//√3/2 sin(60)に相当
void triangle(vector<P> &d, P p0, P p4){
  
}
void Koch_Curve(int n, P p0, P p4){
  if(n == 0) return;
  P p1, p2, p3;
  p1.first  = (2*p0.first  + 1*p4.first)  / (1+2.0);//1:2に内分
  p1.second = (2*p0.second + 1*p4.second) / (1+2.0);//1:2に内分
  
  p3.first  = (1*p0.first  + 2*p4.first)  / (2+1.0);//2:1に内分
  p3.second = (1*p0.second + 2*p4.second) / (2+1.0);//2:1に内分

  //  p1の座標 + p1を中心にp3を60度回転 
  p2.first  = p1.first    +   (p3.first-p1.first) *  (1/2.0)       -   (p3.second-p1.second) * ROOT3_half;
  p2.second = p1.second   +   (p3.first-p1.first) * ROOT3_half   +   (p3.second-p1.second) *  (1/2.0);

  

  Koch_Curve(n-1, p0, p1);
  cout << p1.first << " " << p1.second << endl;
  Koch_Curve(n-1, p1, p2);
  cout << p2.first << " " << p2.second << endl;
  Koch_Curve(n-1, p2, p3);
  cout << p3.first << " " << p3.second << endl;
  Koch_Curve(n-1, p3, p4);
}

int main(){
  int n;
  cin >> n;
  // cout << fixed;//小数点を確実に8桁で表示するためのもの
  // cout << setprecision(8); 
  P p0, p4;
  cout << p0.first << " " << p0.second << endl;
  p0.first = 0;   p0.second = 0;
  p4.first = 100; p4.second = 0;
  Koch_Curve(n, p0, p4);
  cout << p4.first << " " << p4.second << endl;
  return 0;
}


