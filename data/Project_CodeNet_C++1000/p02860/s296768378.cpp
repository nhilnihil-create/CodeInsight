#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
   string S;
   cin >> N >> S;

   if(N % 2 == 1) {
      cout << "No" << endl;
      return 0;
   }

   string a = S.substr(0, N/2);
   string b = S.substr(N/2, N/2);
   if(a == b) {
      cout << "Yes" << endl;
      return 0;
   }
   else {
      cout << "No" << endl;
   }
}