#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define cool ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define MAX 1000001
#define mod 1000000007
#define pie 3.14159265358979323846
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int i,c=0;
	char prev='1';
	for(i=0;i<s.size();i++){
		if(s[i]==prev){
			continue;
		}
		else{
			c++;
			prev=s[i];
		}
	}
	cout<<c;
}
int main()
{ 
    cool;
    int t;
    //cin>>t;
    t=1;
    while(t--){
    	solve();
	}
    return 0;
}
