#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  A--; B--; C--; D--;
  string S;
  cin >> S;
  //入力終了

  //(A, C)に2マス連続で岩があればNG
  for(int i=A+1; i<=C-1; i++){
    if(S[i] == '#' && S[i+1] == '#'){
      cout << "No" << endl;
      return 0;
    }
  }

  //(B, D)に2マス連続で岩があればNG
  for(int i=B+1; i<=D-1; i++){
    if(S[i] == '#' && S[i+1] == '#'){
      cout << "No" << endl;
      return 0;
    }
  }

  //2マス連続で岩がないとき
  //C < Dなら上手く移動できる
  if(C < D){
    cout << "Yes" << endl;
    return 0;
  }
  //D < Cのとき，どこかで追い越す必要がある
  else{
    for(int i=B-1; i<=D-1; i++)
      //3マス連続で空白があればOK
      if(S[i] == '.' && S[i+1] == '.' && S[i+2] == '.'){
	cout << "Yes" << endl;
	return 0;
      }
  }
    
  //上のループを抜けるならダメ
  cout << "No" << endl;
  
  return 0;
}
