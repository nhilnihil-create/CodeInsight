#include <bits/stdc++.h>

using namespace std;

int main() {
 	string a, b;
  cin >> a >> b;
  int lena = a.length();
  int lenb = b.length();
  int mmin = 1 << 30;
  for (int i = 0; i < lena - lenb + 1; i++) {
    int temp = 0;
   	 for (int j = 0; j < lenb; j++) {
       if (a[i + j] != b[j]) 
         temp++;
     }
    mmin = min(mmin, temp);
  }
  cout << mmin << endl;
  return 0;
}
