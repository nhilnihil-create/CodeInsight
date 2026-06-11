#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<utility>
#include<climits>
#include<set>
using namespace std;
#define ll long long

void solve(){
	int i=1;
	int t=5;
	while(t--)
	{
		int a;cin>>a;
		if(a==0)
		{
			cout<<i;
			return;
		}
		i++;
	}
}
int main(){ 
	ios_base::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	    
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif


	    int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
//          cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;

}
