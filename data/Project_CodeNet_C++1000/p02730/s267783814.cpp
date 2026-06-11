#include <bits/stdc++.h>
using namespace std;
int main() {
 string a;
 cin >> a;
  int c = 1;
  int b = a.size();
 for(int i=0;i<b;i++){
   if(a.at(i)!=a.at(b-i-1))c=0;
}
   for(int i=0;i<(b-1)/2;i++){
   if(a.at(i)!=a.at((b-1)/2-i-1))c=0;
}

   for(int i = (b+3)/2;i<b;i++){
   if(a.at(i)!=a.at(b-i-1))c=0;
}
  if(c==1)cout << "Yes" << endl;
  else cout << "No" << endl;
}