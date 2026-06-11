#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
int cnt =0,ans=0;
const int MAX = 510000;

int main(){
    int n ;     cin >> n;
    string s;
    cin >> s;
    int cntw=0,cntr=0;
    for(int i=0;i<n;i++){
        
        if(s.at(i) == 'W')cntw++;
        if(s.at(i) == 'R')cntr++;

    }

    for(int i=0;i<cntr;i++){
        if(s.at(i) =='W')cnt++;
    }
    
    ans = min(cntw,min(cnt,cntr));
    cout << ans << endl;

    }
       
