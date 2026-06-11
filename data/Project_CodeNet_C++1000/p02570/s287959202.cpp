#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
int main()
{
    faster();

    int d,t,m;
    cin>>d>>t>>m;
    int ans = t*m;
    if(ans>=d) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}

