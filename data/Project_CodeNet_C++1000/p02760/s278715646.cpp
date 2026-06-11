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
    ll h,n,k,x,c = 0,a[4][4] = {0};
    map<ll,pair<ll,ll>>m;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> x;
            m[x] = make_pair(i+1,j+1);
        } 
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pair<ll,ll>p = m[x];
        a[p.first][p.second] = 1;
    }
    if((a[1][1]&&a[1][2]&&a[1][3]) ||(a[2][1]&&a[2][2]&&a[2][3]) ||(a[3][1]&&a[3][2]&&a[3][3])){
        cout << "Yes" << endl;
        return 0;
    }
    if((a[1][1]&&a[2][1]&&a[3][1]) ||(a[1][2]&&a[2][2]&&a[3][2]) ||(a[1][3]&&a[2][3]&&a[3][3])){
        cout << "Yes" << endl;
        return 0;
    }
    if((a[1][1]&&a[2][2]&&a[3][3]) || (a[1][3]&&a[2][2] && a[3][1])){
        cout << "Yes" << endl;
        return 0;
    }
    
    cout << "No" << endl;

}