#include <iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    string dog="";
while(n>0){
if(n%26==0){
    dog='z'+dog;
    n--;
}
  else if(n<703){
    char answer=(n%26 - 1)+'a';
    dog=answer+dog;
     }
  else if(n<18279){
     char answer=(n%26 -1)+'a';
    dog=answer+dog;
     }
     else if(n<47255){
     char answer=(n%26 -1)+'a';
    dog=answer+dog;
     }else if(n>47255){
     char answer=(n%26 -1)+'a';
    dog=answer+dog;
     }
     n=n/26;
}
cout<<dog;
}


