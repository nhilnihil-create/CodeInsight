#include<bits/stdc++.h>

using namespace std;
#define m 2019
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
   string s;
    cin>>s;
    
	int suf=0;
	long long as=0;
	int pot=1;
	vector<int> cnt_suf(m);
	cnt_suf[suf]++;
	for(int i=s.size()-1;i>=0;i--)
	{
		int dig=s[i]-'0';
		suf=(suf+dig*pot)%m;
		pot=(10*pot)%m;
		
		as+=cnt_suf[suf];
		cnt_suf[suf]++;
		
		
	}	
		
    

    cout<<as<<endl;
    return 0;
}