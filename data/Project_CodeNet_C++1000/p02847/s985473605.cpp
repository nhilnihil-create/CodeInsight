#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  string s;
  cin>>s;
  if(s[0]=='M')cout<<6<<endl;
  else if(s[0]=='T'&&s[1]=='U')cout<<5<<endl;
  else if(s[0]=='W')cout<<4<<endl;
  else if(s[0]=='T'&&s[1]=='H')cout<<3<<endl;
  else if(s[0]=='F')cout<<2<<endl;
  else if(s[0]=='S'&&s[1]=='A')cout<<1<<endl;
  else cout<<7<<endl;
  return 0;
}
