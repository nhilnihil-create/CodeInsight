#include <bits/stdc++.h>
using namespace std;

int main() {
   string a[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
   string s;
   cin >> s;
   for(int i = 0; i < 7; i++){
     if(s == a[i]) cout << 7-i << endl;
   }
   return 0;
}
