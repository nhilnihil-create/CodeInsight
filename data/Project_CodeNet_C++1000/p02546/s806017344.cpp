#include<iostream>
using namespace std;
int main()
{
    int i,len;
   string str,str1;
   cin>>str;
    len=str.length();
  if(str[len-1]=='s')
  {
      str=str+"es";
  }
  else{

    str=str+"s";
  }
  cout<<str<<endl;


 return 0;
}
