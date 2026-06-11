
// Problem : C - A x B + C
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long   
int mod=1e9+7;
int po(int x,int y,int m)  { if (y==0) return 1; int t=po(x,y/2,m)%m; t=(t*t)%m; if (y&1) return (t*x)%m; return t%m; }

const int mx=1000001;
vector<bool> prim(mx,true); 

void seive(){
    for (int p = 2;p*p<=1000001;p++) {
        if (prim[p]==true) 
            for (int i=p * p;i<=1000001;i += p) 
                prim[i] = false; 
    }
}
                
int div(int n) 
{ 
 	int total = 1; 
    for (int p = 2; p <= n; p++) { 
        if (prim[p]) { 
            int count = 0; 
            if (n%p==0) { 
                while (n%p == 0) { 
                     n=n/p; 
                     count++; 
                } 
                total *= (count + 1); 
            } 
        } 
    } 
    return total; 
} 

signed main() {

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0); 
  
    int n;
    cin>>n;
    seive();
    int ans=0;
    for (int i=1;i<n;++i){
      ans+=floor(n-1)/i;
    }   
    cout<<ans<<endl;
    return 0;
}