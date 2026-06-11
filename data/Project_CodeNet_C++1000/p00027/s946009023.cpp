#define ll    long long
#define pb    push_back
#define mk    make_pair
#define f     first
#define s     second
#define pii   pair<int, int>
#define fuck  return 0;

#include<bits/stdc++.h>
using namespace std;


int main()
{
   string a[7]={"Wednesday","Thursday","Friday","Saturday","Sunday","Monday","Tuesday"} ;
   int sum = 0, day[12]={31,29,31,30,31,30,31,31,30,31,30,31};

   int m, d;

   while((cin >>m >>d) && (m!=0 && d!=0))
   {
       for(int i=0; i<=m-2; i++) sum+= day[i];


       sum += d;
       int ans = sum % 7;
       cout <<a[ans] << endl;
     sum=0;
   }
}

