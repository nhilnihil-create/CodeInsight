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


vi findRange(int tax,double rate){
    int l=round(tax/rate);
    int r=round((tax+1)/rate);
    cout<<l<<" "<<r<<endl;
    return {l,r};
}

void solve(){
    
    int a,b;
    cin>>a>>b;
    
    int f=1;
    for(int i=0;i<1100;i++){
        // cout<<i*0.08<<" "<<i*0.1<<endl;
        if(int(i*0.08)==a && int(i*0.1)==b){
            cout<<i<<endl;
            f=0;
            break;
        }
    }
    if(f){
        cout<<-1<<endl;
    }
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