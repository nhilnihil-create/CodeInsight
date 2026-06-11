#include<bits/stdc++.h>
#define mod 2019
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    map<int,int>rel;
    int pr=1;
    rel[0]++;
    int last=0;
    int cnt=0;
    for(int i=n-1; i>=0; i--)
    {
    	int num=s[i]-'0';
    	last=(pr*num%mod+last)%mod;
    	pr=pr*10%mod;
    	cnt+=rel[last];
    	rel[last]++;
	}
	cout<<cnt;
	return 0;
}