#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define rep(i,start,n) for(int i=start; i<n; i++)

void solve(){
	string s;cin>>s;

	int len = s.length();
	int n = len+1;
	int a[n]={0};

	int i = 0;
	int cnt = 0;
	while(s[i]=='>' && i<len){cnt++;i++;}

	int ans = cnt;
	a[0]=cnt;
	int p=1;
	while(cnt--){a[p++]=cnt;ans+=cnt;}

	// loop(n)cout<<a[i]<<" ";

	for(;i<len;i++){

		int inc = 0;
		int dec = 0;
		while( s[i]=='<' && i<len ){inc++;i++;}
		while( s[i]=='>' && i<len ){dec++;i++;}

		// cout<<" -> "<<i<<" "<<inc<<" "<<dec<<endl;

		if(inc<dec){
			//take dec
			ans+=( dec*(dec+1) )/2;
			ans+=( inc*(inc-1) )/2;
		}
		else{
			ans+=( inc*(inc+1) )/2;
			ans+=( dec*(dec-1) )/2;
		}
		i--;
		
	}
	cout<<ans<<endl;
	//			0
	
 	// <    +   3  
	// >>>  - - - 2 1 0

	// <<   + +  1 2
	// >    -    0

	// <<<<< + + + + + 1 2 3 4 5
	// >>>   - - -     2 1 0

 	// <     + 1


	
}
	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}
