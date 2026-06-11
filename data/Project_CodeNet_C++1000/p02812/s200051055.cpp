#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int m=1e9+7;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;++i){
    	if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
    		++cnt;
    		i+=2;
    	}
    }
    cout<<cnt;
    return 0;
}

