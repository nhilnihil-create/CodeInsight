#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
   string s;
   cin >> s;
   int cnt = 0;
   rep(i,s.size()/2){
      if (s[i] != s[s.size() - 1 - i]) cnt++;
   }
   cout << cnt << endl;

   return 0;
   

}
