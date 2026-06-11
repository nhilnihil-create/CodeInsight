#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

void solve(){
    int n,m;
    cin>>n>>m;
    
    vector<bool> AC(n+1,false);
    vector<int> P(n+1,0);
    
    int ac=0,pen=0;
    
    for(int i=0;i<m;i++){
        int pro;
        string s;
        cin>>pro>>s;
        if(AC[pro]==false){
            if(s=="AC"){
                pen+=P[pro];
                AC[pro]=true;
                ac++;
            }
            else{
                P[pro]++;
            }
        }
    }
    cout<<ac<<" "<<pen;
}





int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}