#include<iostream>
#include<cstring>

using namespace std;

int main()
{
  string s;
  
  cin >> s;
  
  if(s=="RRR")
    cout << 3;
  if(s=="RRS"||
     s=="SRR")
    cout << 2;
  if(s=="SRS"||
     s=="RSS"||
     s=="SSR"||
     s=="RSR")
    cout << 1;
  if(s=="SSS")
    cout << 0;
}
  
