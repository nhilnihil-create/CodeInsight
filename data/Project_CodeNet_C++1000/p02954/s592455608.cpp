#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
#define PI 3.141592653
using namespace std;

int f[100001];

void solve(){

	string s; cin>>s;
	int m=0;
	std::vector<int> v1,v2;
	for(int i=0; i<s.length(); i++){
		if(s[i] == 'R'){
			m++;
			if(s[i+1] == 'L'){
				v1.pb(i);
				v1.pb(i+1);
				v2.pb(m);
				m=0;
			}
		}
		else{
			m++;
			if(i != s.length()-1 && s[i+1] == 'R'){
				v2.pb(m);
				m=0;
			}
		}
	}
	v2.pb(m);
	for(int i=0; i<v1.size(); i++){
		if(i%2 == 0){
			f[v1[i]] += v2[i] - (v2[i]/2);
			f[v1[i+1]] += v2[i]/2;
		}
		else{
			f[v1[i]] += v2[i] - v2[i]/2 ;
			f[v1[i-1]] += v2[i]/2;
		}
	}
	for(int i=0; i<s.length(); i++) cout<<f[i]<<" ";


}

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(12);

    int t =1; //cin>>t;
    for(int i=1; i<=t; i++){
        solve();
        cout<<"\n";
    }
    return 0;

}