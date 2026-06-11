#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
       fast;
       string s;
       cin>>s;
       int arr[26]={0},cnt=0;
       for(int i=0;i<s.length();i++)
       {
       		arr[s[i]-'A']++;
       }
       for(int i=0;i<26;i++)
    		if(arr[i])
    			cnt++;
    	if(cnt==2)
    		cout<<"Yes";
    	else
    		cout<<"No";
       return 0;
}
