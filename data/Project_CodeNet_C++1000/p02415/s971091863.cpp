#include<bits/stdc++.h>//本当は必要なヘッダファイルだけインクルードするべきです
using namespace std;//本当は個別にusingするか変数や関数ごとにstd::をつけるべきです
//本当は関数内に宣言し明示的に初期化するべきです
string s;
long l,i;
int main(void){
  getline(cin,s);
  l=s.size();
  for(i=0;i<l;i++){
    if(isupper(s[i]))cout<<(char)tolower(s[i]);
    else if(islower(s[i]))cout<<(char)toupper(s[i]);
    else cout<<s[i];
  }
  cout<<endl;
  return 0;
}

