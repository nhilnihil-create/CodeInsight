#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main(void){
    // Your code here!
 int i,n;
 string s;
 cin >> s;
 n=s.length();
 for(i=0;i<n;i++)
 {
  if((i%2 && s[i]=='R') || (i%2==0 && s[i]=='L'))
  {
   cout << "No";
   return 0;
  }
 }
 cout << "Yes";
 return 0;
}
