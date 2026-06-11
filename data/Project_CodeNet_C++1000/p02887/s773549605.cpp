#include<bits/stdc++.h>

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ll long long 
 
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int left=0;
	int right=1;
	int c=0;
     while(left<n)
     {
          if(s[left]==s[right])
          {
               c++;
               while(s[left]==s[right]&&right<n)
               {
                    right++;
               }
               left=right;
               right++;
          }
          else{
          c++;
          left++;
          }
          
     }
     cout<<c;

	return 0;
}