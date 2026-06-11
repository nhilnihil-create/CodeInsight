#include <bits/stdc++.h>
using namespace std;
 char c[101];
 int main(void) {
 cin>>c;
 int res = 0;
 int n = strlen(c);
 for (int i = 0; i < n; i++) {
 	if (c[i] != c[n - 1 - i]) 
      res++;
 }
cout<<res/2;
   return 0;
}