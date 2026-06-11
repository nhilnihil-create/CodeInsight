#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()0
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!



void solve(){
    int n;
    cin>>n;
    
    priority_queue<double,vector<double>,greater<double>> pq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    if(n==0){cout<<0<<endl;return ;}
    
    
    while(pq.size()>1){
        double a=pq.top();
        pq.pop();
        double b=pq.top();
        pq.pop();
        double sum=(a+b)/2;
        pq.push(sum);
    }
    
    cout<<pq.top()<<endl;
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