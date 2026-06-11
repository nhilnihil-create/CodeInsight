#include <bits/stdc++.h>
using namespace std;
int nCrModpDP(int n, int r, int p) 
{ 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
  
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}
int nCrModpLucas(int n, int r, int p) 
{ 
   if (r==0) 
      return 1; 
  
   int ni = n%p, ri = r%p; 
  
   return (nCrModpLucas(n/p, r/p, p) * nCrModpDP(ni, ri, p)) % p;  
}
int main()
{
    int n;cin>>n;
    string s;cin>>s;
    int two=0;
    for(int i=0;i<n;i++){
        if(s[i]=='2'){
            s[i]-=2;
            two++;
        }
    }
    if(two>0){
        for(int i=0;i<n;i++){
            if(s[i]=='2') s[i]-=2;
            if(s[i]=='3') s[i]-=2;
        }
        long long one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one+=nCrModpLucas(n-1,i,2);
            }
        }
        if(one%2==0){
            cout<<0;
        }else{
            cout<<1;
        }
    }else{
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') s[i]-=1;
            if(s[i]=='3') s[i]-=2;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1') one+=nCrModpLucas(n-1,i,2);
        }
    if(one%2==0) cout<<0;
    else cout<<2;
    }
    
    return 0;
}
