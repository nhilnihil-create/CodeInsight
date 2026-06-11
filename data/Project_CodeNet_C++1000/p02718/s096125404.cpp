#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,votes = 0,i,cnt = 0;
    cin>>n>>m;
    int t[n];
    for(i = 0;i<n;++i){
        cin>>t[i];
        votes += t[i];
    }
    i = 0;
    cnt = 0;  
    int cmp = ceil((double)votes/(4*m));
      
    while(cnt<m && i<n){
        if(t[i]>=cmp){
            cnt++;
        }
        i++;
    }
    if(cnt == m){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}