
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
  
	ll a,i,sum=0;
	
	cin >> a;
  for(i=1;i<=a;i++)
  {
    if(i%3==0 || i%5==0)
    continue;
    sum+=i;
  }
  cout<<sum<<endl;



  
}
//Apna Time Aayega :)