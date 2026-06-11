#include<iostream>
#include<string>

using namespace std;

int main(void){

  string N;
  int ans = 0;
  cin >> N;

  for(char s :N){
    ans += s - '0';
  }

  if(ans%9 == 0){
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;

}
