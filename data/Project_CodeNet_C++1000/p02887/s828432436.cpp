#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define forn(i,n) for(int i=0;i<(int) n;i++)
#define Forn(i,n) for(int i=1;i<=(int) n;i++)

int main()
{

int n;
cin>>n;
string s;
cin>>s;
  int i,j,c=1;
 if(n==1)
 {
     cout<<1;
     return 0;
 }
 for(i=1;i<n;i++)
 {
     if(s[i]!=s[i-1]) c++;
 }
 cout<<c;

}




