#include <bits/stdc++.h>
using namespace std;
#define rep(i,k,n) for(int i = k; i < n; i++)  
#define repp(i,k,n) for(int i = k; i <= n; i++) 
#define per(i,k,n) for(int i = k; i >= n; i--)

#define int long long
#define all(a) a.begin(),a.end()       

#define pb push_back
typedef long long ll; 
typedef pair<int, int> ii;
typedef pair<int,ii > iii; 
typedef vector<ii> vii;
typedef vector<char> vchar;
typedef vector<int> vi;
#define ff first
#define ss second

#define mem(a, b) memset(a, b, sizeof(a));
#define mem0(a) memset(a, 0, sizeof(a));

#define INF 1000000000
//#define mod 998244353
#define mod 1000000007
#define endl "\n"


   //=\/=\/=\/=\/=\/=\/=\/=\/=\/=\        Jai Hind Dosto        /=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\\
  //=\/=\/=\/=\                    ̿̿ ̿̿ ̿̿ ̿'̿'\̵͇̿̿\з= ( ▀ ͜͞ʖ▀) =ε/̵͇̿̿/’̿’̿ ̿ ̿̿ ̿̿ ̿̿                             /=\/=\/=\/=\\
 //=\/=\/=\/=\                                                                               /=\/=\/=\/=\\
//=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\\



int modPow(int a, int b);      

                
void solve(){
    int n;
    cin >> n;
    int a[n];
    rep(i,0,n)cin >> a[i];
    sort(a,a+n);
   
   set<int> x;
   int maxo = 0;
   set <int> y;
    rep(i,0,n){
        y.insert(a[i]);
        if(i<n-1){
            if(a[i]==a[i+1])continue;
        }
        if(i>0){
            if(a[i]==a[i-1])continue;
        }
        maxo = max(maxo, a[i]);
        x.insert(a[i]);
    }

    
    int cnt=0;

    bool hehe[maxo+1]={0};

    for(auto i : y){
    
        int temp =2*i;
        while(temp <=maxo && hehe[i]==0){
            hehe[temp]=1;
            temp += i;
        }
    }
    cnt =0;
    for(auto i : x){
        if(hehe[i]==0)cnt++;
    }
    cout << cnt;
}






signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed;
    //cout <<setprecision(6);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
   // int test=1; cin >> test; while(test--)
    solve();
}

int modPow(int a, int b){
    if(b==0)return 1;
    if(b%2==0){
        int x = a*a;
        x%=mod;
        return modPow(x,b/2);
    }
    return (a*modPow(a,b-1))%mod;
}


 