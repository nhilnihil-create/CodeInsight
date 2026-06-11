#include <bits/stdc++.h>
#include<cmath>
#include<iomanip>
#include <algorithm>
#include<string.h>
#include<queue>
#include<deque>
#include<set>

using namespace std;
//cout<<setprecision(9)<<fixed<<a;
typedef long long ll;


int main()

{

     int n;
     cin>>n;
     while(1)
     {
          bool p=true;
         for(int i=2; i*i<=n; i++)
         {
             if(n%i==0)
             {
                   p=false;
                   n++;
                  break;
             }

         }
         if(p)
         {
             return cout<<n,0;
         }

     }

}









