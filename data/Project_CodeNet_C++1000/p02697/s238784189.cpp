//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

int main(){
   IOS
    
    int n, m; cin>>n>>m;

    int i = 1, d = (m>>1) * 2;
    for(; d >= 2; d-= 2){
        cout<<i<<" "<<i + d<<"\n";
        i++;
    }

    if(m & 1) d = m;
    else d = m-1;

    i = 2 + ((m>>1) * 2);
    for(; d >= 1; d-=2){
        cout<<i<<" "<<i+ d<<"\n";
        i++;
    }  

}


