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
    
    ll a,b;
    cin >> a >> b;
    if(a > b){
    for (int i = 0; i < a; i++)
        {
            cout << b;
        }
        cout << endl;
    }else
    {
        for (int i = 0; i < b; i++)
        {
            cout << a;
        }
        cout << endl;
        
    }
    
        
}