#include<bits/stdc++.h>
#define unsigned long long ull
#define long long ll
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)

using namespace std;

void solve(){            
    int x,y;
    cin>>x>>y;
    int maxlegs = x*4;
    int minlegs = x*2;
    if(y>= minlegs && y<= maxlegs && y%2==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    solve();    
    return 0;
}