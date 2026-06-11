#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
long long n,a,k=0,i,c=0;
string str="";
char ch;
cin>>n;
while(n>0){
        a=n%26;
       k=n/26;
       c++;
      if(a==0){
          k--;
          a=26;
          
      }
       ch=96+a;
      str+=ch;
      n=k;
}
reverse(str.begin(),str.end());
cout<<str;
}