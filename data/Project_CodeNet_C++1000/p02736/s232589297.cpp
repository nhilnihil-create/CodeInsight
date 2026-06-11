#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD=1e9+7;

//const int MOD=998244353;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        v[i]=(s[i]-'1');
    }
    
    vector<int> tct(n);
    for(int i=1; i<n; i++){
        int ct=0, cur=i;
        while(!(cur%2)){
            cur/=2;
            ct++;
        }
        tct[i]=tct[i-1]+ct;
    }
    bool has1=0;
    for(int i:v){
        if(i==1){
            has1=1;
            break;
        }
    }
    if(has1){
        int ans=0;
        for(int i=0; i<n; i++){
            int ct=tct[n-1]-tct[i]-tct[n-1-i];
            if(!ct){
                ans+=v[i];
            }
            
            ans%=2;
        }
        cout<<ans;
        return 0;
    }
    int ans=0;
    for(int i=0; i<n; i++){
        int ct=tct[n-1]-tct[i]-tct[n-1-i];
        if(!ct){
            ans+=v[i]/2;
        }
        
        ans%=2;
    }
    cout<<2*ans;
    return 0;
}