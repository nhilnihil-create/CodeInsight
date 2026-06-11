#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl;
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   " << endl;
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}
 

int main(){
  ll X;
  cin >> X;


  //A^5 - B^5 = (A-B)^5 + 5AB(A-B)^3 + 5{(AB)^2}(A-B)
  const ll SIZE = 1000;
  for(ll A=-SIZE; A<=SIZE; A++){
    for(ll B=-SIZE; B<=SIZE; B++){
      ll ko1 = (A-B)*(A-B)*(A-B)*(A-B)*(A-B);
      ll ko2 = 5 * A * B * (A-B)*(A-B)*(A-B);
      ll ko3 = 5 * A*A*B*B * (A-B);
      if(ko1+ko2+ko3 == X){
        cout << A << " " << B << endl;
        return 0;
      }
    }
  }
  cout << " Nothing!!" << endl;
  return 0;

  //以下の解法だと X=3とかで答えが出なかった
  // const ll SIZE = 1000;
  // for(ll A=-SIZE; A<=SIZE; A++){
  //   for(ll B=-SIZE; B<=SIZE; B++){
  //     if(A*A*A*A*A == B*B*B*B*B + X){
  //       cout << A << " " << B << endl;
  //       return 0;
  //     }
  //   }

  // }
  // return 0;

    
}
