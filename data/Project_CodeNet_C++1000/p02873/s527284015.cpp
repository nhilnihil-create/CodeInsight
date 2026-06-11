#include <iostream>
#define ll long long
#include <cstring>
using namespace std;

int arr[500005];
int main() {
  string s;
  cin >> s;

  memset(arr, 0, sizeof(arr));

  ll ans = 0;
  int cntr = 0;
  for (int i = 0; i < s.length(); i++){
    if (s[i] == '<'){
      arr[i+1] = arr[i]+1;
    }
  }

  for (int i = s.length()-1; i >= 0; i--){
    if (s[i] == '>'){
      if (arr[i] < arr[i+1] + 1)
        arr[i] = arr[i+1] + 1; 
    }
    ans = ans + arr[i];
  }


  cout << ans + arr[s.length()] << endl;
}