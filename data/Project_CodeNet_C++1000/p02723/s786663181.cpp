#include <bits/stdc++.h>
using namespace std;
int main()
{
string s;
char ch[6];
cin >> s;
for(int i=0;i<6;i++)
{
ch[i]=s.at(i);
}
if(ch[2]==ch[3] && ch[4]==ch[5])
{
cout << "Yes";
}
else
{
cout << "No";
}
return 0;
}
