#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
#define pb push_back
#define vv vector<ll>
#define fr(i,x) for(int i=0;i<x;i++)
#define MAX 10000005
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    
    if(a.first == b.first) return a.second<b.second;
    return (a.first < b.first); 
}

ll a[MAX];
void sieve(){
    for (int i = 1; i < MAX; i++)
    {
        for (int j = i; j <= MAX; j+=i)
        {
            a[j]++;
        }
        
    }
    
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    

    ll n,d,x,y,r,cnt = 0,k;
    cin >> n >> d;
    while (n)
    {
        cin >> x >> y;
        //cout << sqrt(pow(x,2)+pow(y,2)) << endl;
        //cout << h << endl;
        if(sqrt(pow(x,2)+pow(y,2)) <= d) cnt++;
        n--;
    }
    cout << cnt << endl;
    
   
    
    
    
    
    
    
}