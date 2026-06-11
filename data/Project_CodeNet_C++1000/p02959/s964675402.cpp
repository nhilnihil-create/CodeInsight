//s.empty() //emptyなら1を出力 入っていれば0を出力
/*//ABC018-B 部分的にreverseをかける解法
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  rep(i,n)a.at(i)--;
  rep(i,n)b.at(i)--;
  string t;
  rep(i,n){
    t = s;
    for(int k=0;k<=b.at(i)-a.at(i);k++){
      t.at(a.at(i)+k) = s.at(b.at(i)-k);
    }
    s = t;
  }
  cout << s << endl;
}
*///ABC018-B
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
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int kaijou(int n){
  int kaijou_sum = 1;
  if(n!=0){
    for(int i=1;i<=n;i++){
      kaijou_sum *= i;
    }
    return kaijou_sum;
  }
  else return 1;
}

int main() {
  ll n;
  cin >> n;
  vector<ll>a(n+1);
  vector<ll>b(n);
  rep(i,n+1)cin>>a.at(i);
  rep(i,n  )cin>>b.at(i);
  ll sum = 0;
  ll tmp = 0;
  for(int i=0;i<n;i++){
    ll A = a.at(i);
    ll B = b.at(i);
    if(tmp!=0){
      if(A<tmp){
        sum += A;
        A = 0;
      }
      else{
        A = A - tmp;//Aは負の数になってはいけない
        sum += tmp;
      }
      tmp = 0;
    }
    if(A >= B){
      sum += B;
    }
    else{
      sum += A;
      tmp = B - A;
    }
  }
  // A n+1 wosaigonimiru
  ll A = a.at(n);
    if(tmp!=0){
      if(A<tmp){
        sum += A;
        A = 0;
      }
      else{
        A = A - tmp;//Aは負の数になってはいけない
        sum += tmp;
      }
      tmp = 0;
    }
  cout << sum << endl;
}