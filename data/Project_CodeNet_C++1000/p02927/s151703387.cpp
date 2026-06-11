#include <bits/stdc++.h>
using namespace std;
#define all int i=0; i<n; i++
#define pb push_back
typedef long long int ll;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define mod 1000000007

bool sortinrev(const pair<ll,ll> &a,  
               const pair<ll,ll> &b) 
{ 
       return (a.first > b.first); 
}
int main(){
	int m,d,ans=0;
	cin>>m>>d;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=d; j++){
			if(j/10 >=2 && j%10>=2 && (j/10) * (j%10) == i)ans++;
		}
	}
	cout<<ans<<endl;
}
