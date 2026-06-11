#include <iostream>
#include <string>

using namespace std;

int main(){
   char s;
   cin >> s;
   string ans;
   ans = isupper(s)? "A":"a";
   cout << ans << endl;
   return 0;
}