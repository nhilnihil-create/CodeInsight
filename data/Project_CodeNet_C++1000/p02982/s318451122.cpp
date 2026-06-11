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


int square(int x){
    return x*x;
}
bool isPerfectSquare(int x){
    int sq=sqrt(x);
    return sq*sq==x;
}
bool check(const vector<int> &p1,const vector<int> &p2){
    int sum=0;
    for(int i=0;i<p1.size();i++){
        sum+=square(p1[i]-p2[i]);
    }
    return isPerfectSquare(sum);
}
void solve(){
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> points(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>points[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(check(points[i],points[j]))
                cnt++;
        }
    }
    cout<<cnt<<endl;
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