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
        
        string s;cin>>s;
        string t;cin>>t;
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++) if(s[i]!=t[i]) c++;
        cout<<c<<"\n";
        
    }
}