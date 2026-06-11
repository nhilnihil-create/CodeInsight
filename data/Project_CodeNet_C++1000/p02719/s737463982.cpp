   /*Bismillahir Rahmanir Rahim*/


#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define ll long long int
#define dd double
using namespace std;

int main()
{
 long long a,b,x,y;
 cin>>a>>b;
  x=a%b;
  y=abs(x-b);
 if(x<y)
 cout<<x<<endl;
 else
 {
    cout<<y<<endl;
 }
 
 
}