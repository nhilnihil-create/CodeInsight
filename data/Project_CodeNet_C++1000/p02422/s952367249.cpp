#include<iostream>
#include<string>

using namespace std;

int main(){
  string str;

  cin >> str;

  int n;

  cin >> n;



  for(int i=0;i<n;i++){
      string order,replace;
      int a,b;
      cin >> order >> a >> b;
      if(order == "replace") cin >> replace;

      if(order == "replace") str.replace(a,b-a+1,replace);
      else if(order == "reverse") {
        string reverse;
        reverse = str.substr(a,b-a+1);
        for(int j=0;j<b-a+1;j++){
          str[a+j] = reverse[b-a-j];
        }
      }
      else if(order == "print") cout << str.substr(a,b-a+1) << endl;
  }

  return 0;
}