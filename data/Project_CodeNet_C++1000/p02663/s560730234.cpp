#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int h1,m1,h2,m2,k; cin>>h1>>m1>>h2>>m2>>k;
	int ans=(h2-h1)*60;
	if(m1<=m2) ans+=m2-m1;
	else ans-=m1-m2;
	cout<<ans-k<<endl;
}