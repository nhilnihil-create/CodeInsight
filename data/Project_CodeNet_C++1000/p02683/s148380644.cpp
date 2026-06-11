//  s.at(0) = toupper(s.at(0));//小文字なら大文字へ//大文字の場合はそのまま
//  s.at(i) = tolower(s.at(i));//大文字なら小文字へ//小文字の場合はそのまま
//  string s;
//  cin >> s;
//  cout << s.at(0) <<endl;
//  cout << s.at(0)-'0' <<endl;
//  Aが16？
//  cout << char(i+48) << endl;//なぜかaは47と得る時がある。+48で出力もaにできる。
//  cout << char(97) << endl;//アスキーコードでaを出力
// sort(b.begin(), b.end());//bという配列を小さい方からソート
// reverse(b.begin(), b.end());//bという配列をリターン
// 10桁でdouble出力するパターン１ 
// printf("%.10f\n", ma);
// 10桁でdouble出力するパターン２
//cout << fixed << setprecision(10);
//  cout << ma << endl;

/*01 02 03 12 13 23　と６回見ていくパターン 
for(int i=0;i<n-1;i++){
  for(int j=i+1;j<n;j++){
    }
  }
*///vector<vector<int>> data(3, vector<int>(4));//int型の2次元配列(3×4要素の)の宣言
//int64_t a;
//10のi乗pow(10, i);
/*string s; stringでの文字列を数字型に変える方法
  cin >> s;
  rep(i,s.size()-2) {
  int a= (s.at(i)-'0')*100 + (s.at(i+1)-'0')*10+ s.at(i+2) -'0';
    */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int n,m,x;
  cin >> n >> m >> x;
  vector<int>c(n);
  int ans = 10000000000;
  vector<vector<int>> a(n, vector<int>(m));//int型の2次元配列(3×4要素の)の宣言
  rep(i,n){
    cin >> c.at(i);
    for(int j=0;j<m;j++){
      cin >> a.at(i).at(j);
    }
  }
  //入力できているかテスト
/*  rep(i,n){
    cout << c.at(i) << " ";
    for(int j=0;j<m;j++){
      cout << a.at(i).at(j) << " ";
    }
    cout << endl;
  }
}
*/
  int flag = 0;
  int count = 0;
  int okane = 0;
  vector<int>check(m);
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) {
     vector<int>check(m);  
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }

//        cout << bit << ": {";

      okane = 0;//shokika
      for (int i = 0; i < (int)S.size(); ++i) {
          okane += c.at(S.at(i));
        for(int j=0;j<m;j++){
          check.at(j) += a.at(S.at(i)).at(j);
        }
      }
      count = 0;
      
      rep(i,m){
        if(check.at(i) >= x)count++;
      }
      if(count==m){
        ans = min(ans,okane);
        flag = 1;
      }
      
//        cout << "}" << endl;
//      cout << check.at(0) << " " << check.at(1) <<" "<< check.at(2) << endl;
    }
  
  
  if(flag==0){
    cout << -1 << endl;
  }
  else{
    cout << ans <<endl;
  }
}
