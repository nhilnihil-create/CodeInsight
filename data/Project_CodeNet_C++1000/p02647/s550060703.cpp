#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)

using namespace std;
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
bool check(vector<int>a){
  if(a[0]!=(int)a.size()) return false;
  rep(i,1,a.size()){
    if(a[i]!=a[i-1]) return false;
  }
  return true;
}
void solve(vector<int>&a ,int n,int k){
  if(check(a) || k<=0) return;
  vector<int> pre(n,0);
  rep(i,0,n){
    pre[max(i-a[i],0)]++;
    if(min(n-1,i+a[i])+1<n) pre[min(n-1,i+a[i])+1]--;
  }
  rep(i,1,n) pre[i]+=pre[i-1];
  rep(i,0,n) a[i]=pre[i];
  k--;
  solve(a,n,k);
}
int main(){
    optimizeIO();
    int n,k;
    cin>>n>>k;
    std::vector<int>a(n);
    rep(i,0,n) cin>>a[i];
    solve(a,n,k);
    rep(i,0,n) cout<<a[i]<<" ";
    cout<<endl;
}
