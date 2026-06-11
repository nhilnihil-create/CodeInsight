#include <iostream>
using namespace std;
 
int c[27];
int s[366][27];
int t[366];
int last[27];


 
/*int dissatisfied(int d){
    int dis=0;
    for(int j=1;j<=26;j++){
        dis+=c[j]*(d-last[t[d]]);
    }
    return dis;
}
 
 
int solve(int d){
    int res=0;
    for(int i=1;i<=d;i++){
        res=res+s[i][t[i]]-dissatisfied(i);
    }
    return res;
}*/
 
 
int main(void){
    int D;cin>>D;
    
    for(int i=1;i<=26;i++){
        cin>>c[i];
    }
    
    for(int i=1;i<=D;i++){
        for(int j=1;j<=26;j++){
            cin>>s[i][j];
        }
    }
    
    for(int i=1;i<=D;i++){
        cin>>t[i];
    }
    int v=0;
    for(int i=1;i<=D;i++){
        cin>>t[i];
        last[t[i]]=i;
        v+=s[i][t[i]];
        
        for(int j=1;j<=26;j++) v-=c[j]*(i-last[j]);
        cout<<v<<endl;
        
        
        //cout<<solve(i)<<endl;
    }
    
    return 0;
    
}