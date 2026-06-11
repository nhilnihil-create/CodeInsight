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
        
        ll n;cin>>n;
        string ans;
        while(n>0)
        {
            int d=n%26;
            if(d==0)
            {
                ans.pb('z');n=n/26;n=n-1;
            }
            else
            {
                char ch1=char('a'+d-1);
                ans.pb(ch1);
                n=n/26;
            }
        }
        
        reverse(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }
}