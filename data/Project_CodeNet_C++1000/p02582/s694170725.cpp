#include <iostream>
#include <string>

#define ll long long
#define repeat(i, x) for(register ll i = 0; i < x; i++)

using namespace std;

int main()
{
  string S; cin >> S;

  if(S[0] == 'R' || S[1] == 'R' || S[2] == 'R') {
    if(S[0] == 'R' && S[1] == 'R' && S[2] == 'R') {
      cout << 3 << endl;
    }else if(S[1] != 'R') {
      cout << 1 << endl;
    }else if(S[0] == 'R' || S[2] == 'R') {
      cout << 2 << endl;
    }else{
      cout << 1 << endl;
    }
  }else{
    cout << 0 << endl;
  }
}