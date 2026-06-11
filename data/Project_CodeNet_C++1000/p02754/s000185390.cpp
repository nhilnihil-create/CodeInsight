#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
#define pb push_back
#define vv vector<ll>
#define MAX 105000
#define fr(i,x) for(int i=0;i<x;i++)
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    
    if(a.first == b.first) return a.second<b.second;
    return (a.first < b.first); 
}
ll ar[MAX];
void divisor(){
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = i; j <= MAX;j+=i)
        {
            ar[j]++;
            
        }
        
        
    }
    
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n,a,b;
    cin >> n >> a >> b;
    if(a==0&&b==0)cout << 0 << endl;
    else if(a==0) cout << 0 << endl;
    else if(b==0)cout << n << endl;
    else
    {
        ll c,r;
        
        c = (n/(a+b));
        r = (n%(a+b));
        r = min(r,a);
        cout << (c*a)+r << endl;
 
        
    }
    
    


}