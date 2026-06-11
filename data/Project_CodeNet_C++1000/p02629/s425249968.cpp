#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
   ll n,rem;
   cin>>n;
   string s;

   while(n)
   {
       n--;
    rem=n%26;
    s+=(char)('a'+rem);

    n/=26;
   }
    reverse(s.begin(),s.end());
    cout<<s<<endl;

}

