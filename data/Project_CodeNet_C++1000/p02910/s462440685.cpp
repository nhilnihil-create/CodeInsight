#include<iostream>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    // 文字列の入力
    string s;
    cin >> s;

    // 出力
  	rep(i,s.size()){
      if(i % 2 == 0){
        if(s.at(i) == 'L'){
          cout << "No" << endl;
          return 0;
        }
      }
	  else if(i % 2 == 1){
        if(s.at(i) == 'R'){
          cout << "No" << endl;
          return 0;
        }
      }
    }
   cout << "Yes" << endl;

    return 0;
}