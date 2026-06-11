#include<iostream>
#include<string>
using namespace std;
int main () {
  string S;
  cin >> S;
  string ans[] = {"hi", "hihi", "hihihi", "hihihihi", 
                  "hihihihihi"};
  for (int i = 0; i < 5; i ++) {
    if (S == ans[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}