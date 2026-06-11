#include <iostream>
using namespace std;

int main() {
	string s;
  string t;
  cin >>s;
  cin >>t;
  if (s == t.substr(0,t.length()-1))
  {
    cout<<"Yes";
  }
  else
  {
    cout<<"No";
  }
	return 0;
}
