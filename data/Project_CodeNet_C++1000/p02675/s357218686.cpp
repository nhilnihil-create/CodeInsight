#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
  string s;
  cin>>s;
   int x=s.length()-1;
  if(s[x]=='2' || s[x]=='4' || s[x]=='5'|| s[x]=='7' || s[x]=='9')
    cout << "hon" << endl;
    else if (s[x]=='3')
    cout << "bon" << endl;
  else
    cout << "pon" << endl;

    return 0;

}
