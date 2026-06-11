#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        int k=24*60*60;
        int imos[k+1]={};
        for(int i=0;i<n;i++){
            string l;
            cin>>l;
            int a=((l[0]-'0')*10 + (l[1]-'0'))*60*60 + ((l[3]-'0')*10 + (l[4]-'0'))*60 + ((l[6]-'0')*10 + (l[7]-'0'));
            imos[a]++;
            //cerr<<a<<endl;
            cin>>l;
            a=((l[0]-'0')*10 + (l[1]-'0'))*60*60 + ((l[3]-'0')*10 + (l[4]-'0'))*60 + ((l[6]-'0')*10 + (l[7]-'0'));
            imos[a]--;
            //cerr<<a<<endl;
        }
        for(int i=0;i<k;i++){
            imos[i+1]+=imos[i];
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans=max(ans,imos[i]);
            
        }
        cout<<ans<<endl;
    }
    
}
