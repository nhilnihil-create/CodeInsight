#include <bits/stdc++.h>
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
#define F first
#define S second
#define mp(x,y) make_pair(x,y)
using namespace std;


void solve(){ 
            int h1,h2,m1,m2,k;
            cin>>h1>>m1>>h2>>m2>>k;
            int ans=(h2-h1)*60 +(m2-m1);
            if(ans-k<0) cout<<0<<endl;
            else cout<<ans-k<<endl;
  	
	
	
	
	
	
	
	
	
	
	
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//	freopen("input.txt","r",stdin);
	int t=1;
//	t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




