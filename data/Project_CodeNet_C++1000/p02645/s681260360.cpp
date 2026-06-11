#include <bits/stdc++.h>
using namespace std;

int main(){
int i = 0;
string nm;
cin >> nm;
vector<char> Nickname(nm.begin(),nm.end());

for(i = 0;i < 3;i++)
{
  cout << Nickname[i];
}
  cout << endl;
return 0;
}