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
    
    

    ll n,x,r,cnt = 0;
    cin >> n;
    cout << n + (pow(n,2))+pow(n,3) << endl;
   
    
    
    
    
    
    
    
}