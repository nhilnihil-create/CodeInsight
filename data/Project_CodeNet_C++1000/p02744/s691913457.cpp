#include<bits/stdc++.h>
using namespace std;
int N;
void dfs(string s) {
   if (s.length() == N) {
      cout << s << endl;
      return;
   }
   char moji = 'a';
   for(char c : s) {
      moji = max(c, moji);
   }
   
   for(char str = 'a'; str <= moji + 1; str++) {
      
      dfs(s + str);
   }
}
int main() {
   cin >> N;
   string s = "a";
  dfs(s);
 return 0;

}