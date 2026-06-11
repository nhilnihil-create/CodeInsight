#include<bits/stdc++.h>
using namespace  std;
void sieve(int spf[],int mx){
    spf[1] = 1;
    for(int i=2;i<=mx;i++){
        spf[i] = i ;
    }
    for(int i = 4;i<=mx;i+=2)
        spf[i] = 2;
    for(int i = 3;i*i<=mx;i++){
        
        if(spf[i]==i){
            for(int j = i*i;j<=mx;j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}
int main(){
    int n;
    cin>>n;

    int a[n];
    int mx =0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    int spf[mx+1];
    sieve(spf,mx);
    map<int,int> mp;
    int f = 0;
    for(int i=0;i<n;i++){
        int x =a[i];
       // cout<<x<<endl;
        while(x!=1){
            if(mp[spf[x]]>0){
                
                f=1;
                break;
            }
            mp[spf[x]]++;
            int d =spf[x];
            while(x%d==0)
                x=x/d;
           
        }
        if(f==1)
        break;
    }
    
    int z = a[0];
    for(int i=1;i<n;i++)
        z= __gcd(z,a[i]);
    if(f==0)
    cout<<"pairwise coprime"<<endl;
    else if(z==1)
    cout<<"setwise coprime"<<endl;
    else{
        cout<<"not coprime"<<endl;
    }

}