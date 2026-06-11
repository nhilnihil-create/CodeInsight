//#pragma GCC optimize "trapv"
//-D_GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define ii pair<int,int>
#define Max 100000+5
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f first
#define s second
#define pb push_back
int mod = 1000000007;
int mod1 = 998244353;
vector<int> g[Max];
bool vis[Max];
int d, x, y;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void ex(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        ex(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}


void dfs(int u){

	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]!=1)
			dfs(v);
	}
}



int power(int a,int b){
    if(b==1)return a;
    if(a>mod)a%=mod;
    int r=1;
    while(b){
        if(b&1)r=r%mod*a%mod;
        a=a%mod*a%mod;
        b/=2;
    }
    return r;
}
class uf{
    vector<int> v;
    vector<int> sz;
    
    
    public :
    uf(int n){
        v.resize(n+1);
        iota(v.begin()+1,v.end(),1);
        sz.resize(n+1,1);
        //1 to sz
    }
    int root(int b){
        while(v[b]!=b){
            b = v[b];
        }   
        return b;
    }
    void u(int a, int b){
        //combine a and b
        
        int ra=root(a);
        int rb=root(b);
        if(ra==rb)return ;
        if(sz[ra]<sz[rb]){
            v[ra] = v[rb];
            sz[rb]+=sz[ra];
        }else{
            v[rb]=v[ra];
            sz[ra]+=sz[rb];
        }
    }
    bool f(int a,int b){
        //same set
        return (root(a)==root(b));
    }
   
    
};
vector<int> matmul(vector<int> a,vector<int> b){
    vector<int> c(4,0);
    c[0] = (a[0]%mod*b[0]%mod + a[1]%mod*b[2]%mod)%mod;
    c[1] = (a[0]%mod*b[1]%mod + a[1]%mod*b[3]%mod)%mod;
    c[2] = (a[2]%mod*b[0]%mod + a[3]%mod*b[2]%mod)%mod;
    c[3] = (a[2]%mod*b[1]%mod + a[3]%mod*b[3]%mod)%mod;
    return c;
}
vector<int> id={1,0,0,1};

int32_t main(){
	IO
	//freopen("input.txt","r",stdin);
    	//freopen("output.txt","w",stdout);
	int n;
  	cin>>n;
  	vector<pair<int,int> > v;
  	for(int i=0;i<n;i++){
      int temp;	
      cin>>temp;
      v.push_back({temp,i+1});
    }
  	sort(all(v));
  	for(int i=0;i<v.size();i++)cout<<v[i].second<<" ";
}
