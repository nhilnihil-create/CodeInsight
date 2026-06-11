#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
#define pb push_back
#define vv vector<ll>
#define fr(i,x) for(int i=0;i<x;i++)
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    
    if(a.first == b.first) return a.second<b.second;
    return (a.first < b.first); 
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    

    ll n,x,m,r,cnt = 0,k,y;
    
    cin >> n >> m >> k;
    vector<ll>a,b;a.push_back(0);b.push_back(0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> x;
        a.push_back(x+a[i-1]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        b.push_back(x+b[i-1]);
    }ll res = 0;
    for (int i = 0; i <= n; i++)
    {
        ll t = 0;
        auto it = a.begin();
        if(a[i] <= k) {
           it = upper_bound(b.begin(),b.end(),k-a[i]);
           t += (i+(it-b.begin()-1));
           //t = max(t,(i+(it-b.begin()-1)));
       }
       res = max(t,res);
       
    }
    cout << res << endl;
    
    
    
    
    
    
    
}