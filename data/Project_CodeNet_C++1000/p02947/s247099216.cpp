#include<bits/stdc++.h>
using namespace std;

long long printNcR(int n, int r){
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            long long m = __gcd(p, k); 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
  
    else
        p = 1; 
    return p;
} 

int main(){
    int n;
    map<vector<int>,long long> bmap;
    cin>>n;
    while(n){
        string s;
        vector<int> bset(26,0);
        cin>>s;
        for(auto i:s){
            bset[i-'a']++;
        }
        bmap[bset]++;
        n--;
    }    
    long long ans=0;
    for(auto i:bmap){        
        if(i.second>1){
            ans +=printNcR(i.second,2);
        }        
    }
    cout<<ans;
}