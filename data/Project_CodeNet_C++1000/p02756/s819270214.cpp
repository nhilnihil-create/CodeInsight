#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
	// violinista forever xd
	ios::sync_with_stdio(0),cin.tie(0);
	string s;
	ll q;
	cin>>s>>q;
	ll f,t,m;
	string c;
	m=0;
	while(q--){
    cin>>t;
    if(t==2){
	cin>>f>>c;
	if(m%2){
	if(f==1)f=2;
	else f=1;
	}
	if(f==1)s.insert(0,c);
	else s.push_back(c[0]);
    }else m++;
	}
	if(m%2)reverse(s.begin(),s.end());
	
    cout<<s<<endl;
  
  
	return 0;
}