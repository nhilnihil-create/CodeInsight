#include<iostream>
#include<string>
using namespace std;
int main(){
  string a;
  cin>>a;
  char b,c,d,e;
  b=a.at(0);
  c=a.at(1);
  d=a.at(2);
  e=a.at(3);
  if(b==c&&c==d&&d==e)
    cout<<"No";
  else if((b==c&&d==e)||(b==d&&c==e)||(b==e&&c==d)||(c==d&&b==e)||(c==e&&d==b)||(d==e&&b==c))
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}
    
