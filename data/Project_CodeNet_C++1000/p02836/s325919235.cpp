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
       ll cnt=0;
       for(int i=0;i<s.length()/2;i++)
    		if(s[i]!=s[s.length()-1-i])
				cnt++;
		cout<<cnt;
        return 0;
}
