#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
  string s;
  cin >> s;
  for(int i = 0;i < s.size();i++){
        if(s[i] == '?'){
              s[i] = 'D';
        }
  }
  cout << s << endl;
}
