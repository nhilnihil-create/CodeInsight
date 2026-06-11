#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int h,n;
	cin>>h>>n;
	int k=0;
	rep(i,n) {int a; cin>>a; k+=a;}
	if(k>=h) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}