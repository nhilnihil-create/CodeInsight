//  A bug is never just a mistake. It represents something bigger. An error of thinking that makes you who you are.
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 500009
const int INF = 1.01e9;
#define int int64_t
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


int32_t main(){
		
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    int ppow[n+1];
    ppow[0] = 1;
    rep(i,1,n+1){
    	ppow[i] = ppow[i-1]*10;
    	ppow[i]%=p;
    }

    int h[n+1];
    h[n] = 0 ;
    per(i,0,n){
    	int c = s[i]-'0';
    	h[i] = (h[i+1] + c*ppow[n-1-i])%p;
    }
    unordered_map<int,int> cc;
    cc[0] = 1;
    int ans = 0;
    if(p!=2 && p!=5 && p!=10){
    per(i,0,n){
    	ans+=cc[h[i]];
    	cc[h[i]]++;
    }
    cout<<ans<<"\n";}
    else{
    	if(p==2){
    		int cnn = 0;
    		per(i,0,n){
    			ans+=cnn;
    			if(s[i]=='4' || s[i]=='2' || s[i]=='0' || s[i]=='8' || s[i]=='6'){
    				cnn++;
    				ans++;
    			}
    		}
    		cout<<ans<<"\n";
    	}

    	if(p==5){
    		int cnn = 0;
    		per(i,0,n){
    			ans+=cnn;
    			if(s[i]=='5' || s[i]=='0'){
    				cnn++;
    				ans++;
    			}
    		}
    		cout<<ans<<"\n";
    	}

    	if(p==10){
    		int cnn = 0;
    		per(i,0,n){
    			ans+=cnn;
    			if(s[i]=='0'){
    				cnn++;
    				ans++;
    			}
    		}
    		cout<<ans<<"\n";
    	}

    }
    


}