#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
int n, m, l;
cin >> n >> m >> l;

//行列Aの読み込み
vector< vector<int> > matrix_A(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix_A.at(i).at(j);
    }
  }

//行列Bの読み込み
vector< vector<int> > matrix_B(m, vector<int>(l));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < l; j++) {
      cin >> matrix_B.at(i).at(j);
    }
  }


//結果(積AB)の出力
 for( int i = 0; i < n; i++){
   long int a[l] = {};
   for(int k = 0; k < l; k++){

     for(int j = 0; j < m; j++){
         a[k] += matrix_A.at(i).at(j) * matrix_B.at(j).at(k);
       }
     cout << a[k];
     if(k < l-1) cout << " ";
  }
   cout << endl;
 }
return 0;
}


