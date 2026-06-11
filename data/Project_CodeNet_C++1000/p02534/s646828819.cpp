#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pp;
bool com(pp x,pp y){
    return x.ff<y.ff;
}
int N=1e5+9,k;
void input_(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
}
void solve(){
	int k;
    cin>>k;
    for(int i=0;i<k;i++) cout<<"ACL";
}
int main(){
    input_();
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t=1;
	//cin>>t;
	while(t--) 
	    solve();
	return 0; 
}