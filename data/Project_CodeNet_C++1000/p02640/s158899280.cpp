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
        
        int x,y;cin>>x>>y;
        if(y%2==1)
        {
            cout<<"No"<<"\n";continue;
        }
        int y1=y/2;
        int b=y1-x;
        
        if(b>=0 && x>=b) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
        
        
    }
}