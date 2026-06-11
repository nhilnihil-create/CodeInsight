#include<iostream>
#include<vector>
#define lli long long int
#include<climits>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<map>
#define pb push_back
using namespace std;


lli mgcd(lli a ,lli b)
{
    if(b==0)  return a;
    return mgcd(b,a%b);
}
int main()
{
   
    lli a,b;
    cin>>a>>b;
    lli mul = a*b;
    lli g = mgcd(a,b);
    cout<<mul/g<<endl;
    
    
}

