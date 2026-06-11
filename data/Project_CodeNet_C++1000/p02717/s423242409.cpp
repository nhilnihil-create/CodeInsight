#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long int ll;
void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	swap(x,y);
	swap(x,z);
	cout << x << " " << y << " " << z; 
}
int main(){
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	solve();
	return 0;
}