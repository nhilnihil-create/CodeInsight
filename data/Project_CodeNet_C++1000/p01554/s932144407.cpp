#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main(){
  int n,m;
  vector<string> v;
  string str;
  int flag1 = 0;
  int flag2;
  cin >> n;
  for(int i = 0; i < n;i++){
    cin >> str;
    v.push_back(str);
  }

  cin >> m;

  for(int i = 0;i < m;i++){
    cin >> str;
    flag2 = 0;
    for(int j = 0; j < v.size();j++){
      if(str == v[j]){
        if(flag1 == 0){
          cout << "Opened by "<<str << endl;
          flag2 = 1;
          flag1 = 1;
        }else if(flag1 == 1){
          cout << "Closed by "<< str << endl;
          flag2 = 1;
          flag1 = 0;
        }
      }
    }
    if(flag2 == 0){
      cout << "Unknown " << str << endl;
    }
  }
}