#include<bits/stdc++.h>
using namespace std;
int main() 
{
string S;
cin >> S;
for(int i = 0; i < S.length(); i++) 
  if(S[i] == '?') 
    S[i] = 'D';
  cout << S << "\n";
return 0;
}
