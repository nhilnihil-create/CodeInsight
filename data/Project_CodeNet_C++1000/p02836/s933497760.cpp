#include<bits/stdc++.h>
#define ll long long int
#define Y printf("YES\n")
#define N printf("NO\n")
#define pi acos(-1)
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define r0 return 0

using namespace std;

int main()
{
     string s,str;

     cin>>s;

     str=s;

     reverse(s.begin(),s.end());

     ll k=0;

     for(ll i=0;i<s.size();i++)
     {
         if(s[i]!=str[i])k++;
     }

     cout<<(k+1)/2<<endl;
}
