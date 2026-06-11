#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define first F
#define second S
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, t; 
	cin>>s>>t;
	int tam = s.size(), ans=0;
	for(int i=0; i<tam; i++){
		if(s[i]!=t[i])ans++;
	}
	cout<<ans<<endl;
}
