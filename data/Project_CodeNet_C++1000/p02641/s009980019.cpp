#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <ctime>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define TT int test_cases; cin >> test_cases; while(test_cases--)
#define TT1 int test_cases=1; while(test_cases--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
typedef long long int ll;

 
int main() {
    
    FAST;
    TT1{
        
        int x,n;cin>>x>>n;
        vector<int> p(n);
        unordered_map<int,int> h;
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            h[p[i]]=1;
        }
        int ans=x;
        
        for(int i=0;i<=n;i++)
        {
            int x1=x-i;
            int x2=x+i;
            
            if(h[x1]==0) {ans=x1;break;}
            if(h[x2]==0) {ans=x2;break;}
        }
        cout<<ans<<"\n";
        
        
    }
}