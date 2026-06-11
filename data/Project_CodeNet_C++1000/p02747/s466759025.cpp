#include<string>
#include<iostream>
using namespace std;
int main(void)
{
  string str;
  cin >> str;
  int status = 0;
  for(int i=0; i < (int)str.size(); i++){
    switch(status){
      case 0:
        if(str[i] == 'h') status = 1;
        else status = 3;
        break;
      case 1:
        if(str[i] == 'i') status = 2;
        else status = 3;
        break;
      case 2:
        if(str[i] == 'h') status = 1;
        else status = 3;
        break;
      default:
        status = 3;
        break;
    }
  }
  if(status == 2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}