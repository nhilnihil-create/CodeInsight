// Winners don't quit and Quitters don't win
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mod 998244353
#define MAX 100005
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s,t;
    int i,c=0;
    cin>>s;
    cin>>t;
    for(i=0;i<=2;++i){
    	if(s[i]==t[i]){
    		c++;
		}
	}
	cout<<c;
}