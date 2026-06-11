#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
typedef long long ll;
typedef pair<int,int> pii;

void A(){
	int a,b; cin>>a>>b;
	int cnt=0;
	while(a>0){
		a-=b;
		cnt++;
	}
	cout<<cnt<<endl;
	
}

int main(){
	int a,b,x,t=0;
	cin>>a>>b;
	while(b--){
		cin>>x;
		t+=x;
	}
	cout<<(t>=a?"Yes":"No")<<endl;
}
