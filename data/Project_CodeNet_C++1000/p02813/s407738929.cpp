#include <bits/stdc++.h>

using namespace std;

bool desc(int a,int b){
    return a>b;
}

int main(){
    //int t;
    
    //cin>>t;
    
    //while(t--){
        int n;
        
        cin>>n;
        
        int a[n],b[n],d1=0,d2=0;
        
        string aa,bb,df;
        
        for(int i = 1 ; i <= n ; i++){
            df+=i+'0';
        }
        
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
            aa += a[i]+'0';
        }
        
        for(int i = 0 ; i < n ; i++){
            cin>>b[i];
            bb += b[i]+'0';
        }
        
        while(1){
            if(aa==df) break;
            prev_permutation(aa.begin(), aa.end());
            d1++;
        }while(1){
            if(bb==df) break;
            prev_permutation(bb.begin(), bb.end());
            d2++;
        }
        
        cout<<abs(d1-d2);
        
    //}
    
    return 0;
}