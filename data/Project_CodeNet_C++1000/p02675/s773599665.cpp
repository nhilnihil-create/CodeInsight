#include<iostream>
using namespace std;

int main() {
  int N;
  string ans;
  cin>>N;
  switch (N%10) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
      ans = "hon";
      break;
    case 0:
    case 1:
    case 6:
    case 8:
      ans = "pon";
      break;
    case 3:
      ans = "bon";
      break;
  }
  cout<<ans<<endl;
  return 0;
}
