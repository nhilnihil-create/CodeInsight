#include<bits/stdc++.h>
#define ll long long
#define pb push_back 
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 
	
    string s; 
    cin >> s; 
    int n = s.size() ; 
    vector<int> a(n+1) ;
    int cur = 0 ;  
    for(int i = 0 ; i < n  ; ++i) {
        if(s[i] == '<') {
            a[i+1] = max(a[i]+1, a[i+1]) ; 
        }
         
    } 
    for(int i = n; i>= 0 ; --i) {
        if(s[i]=='>') {
            a[i] = max(a[i+1]+1, a[i]) ; 
        }
       
    }
    
    ll sum = 0 ;  
    for(int i = 0 ; i <= n ;++i) {
        //cout << a[i] << " " ;
        sum += a[i] ; 
    }
    cout << sum ; 
    return 0;
}
