#include <bits/stdc++.h>
#include <string>
//#include <boost/multiprecision/cpp_int.hpp>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll  long long
#define fp cout<<fixed<<setprecision(9);
#define ifor(j,n) for(int i=j ;i<n;i++)
#define jfor(k,n) for(ll j=k ;j<n;j++)
#define pb push_back
#define mod 1000000007
using namespace std;
//using namespace boost::multiprecision;

//Compiler version g++ 6.3.0
struct node
{
 float p;
};
int search (vector <long long> v,long long m,int n) 
{ 

    int start = 0;
    int ans = -1; 
    while (start <=n) 
    { 
     int mid = (start + n) / 2;
     if (v[mid] <= m) 
         start = mid + 1;
     else
   { 
   ans = mid; 
   n = mid - 1; 

       } 

    } 
    return ans; 
} 

int main()
{
 FAST 
   int r,g,b,k;
   cin>>r>>g>>b>>k;
  while(k--)
  {
    if(r>=g)
      g*=2;
    else if(g>=b)
      b*=2;
  }
   if(r<g && g<b)
      cout<<"Yes"<<endl;
   else
     cout<<"No"<<endl;
   
     }
     
