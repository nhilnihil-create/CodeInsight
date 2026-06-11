#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
    int n; cin >> n ;
    string s; cin >> s;
    if(n%2==0){
    	string ans ="", ans2="";
    	for(int i=0 ; i < n/2 ; i++){
    		ans+=s[i];
		}
		for(int i= n/2 ; i < n ; i++){
			ans2+=s[i];
		}
		//cout << ans << " " << ans2 << endl;
		if(ans==ans2)
		cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else cout << "No" << endl;
}