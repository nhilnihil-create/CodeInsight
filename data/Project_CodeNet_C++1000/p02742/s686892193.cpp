#include<bits/stdc++.h>
#define pb push_back
#define inf 0x3f3f3f3f
#define ll unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define mem(a,val) memset(a,val,sizeof(a))
#define mkp make_pair
#define all(n) (n).begin(),(n).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
	ll h,w;
	cin>>h>>w;
	if(h==1 || w==1) cout<<1<<endl;
	else cout<<((h*w+1)>>1)<<endl;
}