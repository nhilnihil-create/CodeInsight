#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define M 1000000007
#define fors(i,n) for(int i=0;i<n;++i)
#define fore(i,a,b) for(int i=a;i<=b;++i)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vv vector<int>
#define endl "\n"
#define test(i) cout<<i<<endl
#define tests(i) cout<<"i: "<<i<<endl;
#define itrt int t; cin>>t; fors(i,t)
#define itr1 int t; cin>>t;
#define ff first
#define ss second
#define pb push_back
#define vmp make_pair
#define ppb pop_back
#define sorta(a,n) sort(arr,arr+n)
#define sortv(x) sort(x.begin(),x.end())
void file(){
    #ifdef LOCAL
    freopen("demo.in","r",stdin);
    freopen("demo.out","w",stdout);
    #endif
}
bool sortdes(const pair<int,int> &a, const pair<int,int> &b){return a.ss<b.ss;}
bool sortasc(const pair<int,int> &a, const pair<int,int> &b){return a.ss>b.ss;} 
int gcd(int x,int y){return __gcd(x,y);}
lld fact(lld n);
lld nCr(lld n,lld r){return fact(n) / (fact(r) * fact(n - r));}
lld fact(lld n){ lld res = 1; for(lld i = 2; i <= n; i++){res = res * i;}return res;} 
const int maxi = 1e6+10;
vector<int> v[maxi];
long long a[maxi];
void dfs(int x,int y){
    a[x]+=a[y];
    for(int i:v[x]){
        if(i!=y){
            dfs(i,x);
        }
    }
}

void test_case(){
    int a,b,c;
    cin>>a>>b>>c;
    int sum=c-(a-b);
    if(sum<0){
        cout<<"0";
    }
    else{
        cout<<sum;
    }
    
}

int main(){
    fastio;
    file();
    int T=1;
    // int T;
    // cin>>T;
    for(int nr=1;nr<=T;++nr) {
        // cout<<"Case #"<<nr<<": ";
		test_case();
    }
}