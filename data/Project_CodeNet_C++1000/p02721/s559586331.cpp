#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c,k;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    int l[n]={},r[n]={};
    int x=1;
    for(int i=0;i<n && x<=k;i++){
        if(s[i]=='o'){
            l[i]=x;
            x++;
            i+=c;
        }
    }
    x=k;
    for(int i=n-1;i>=0 && x;i--){
        if(s[i]=='o'){
            r[i]=x;
            x--;
            i-=c;
        }
    }
    for(int i=0;i<n;i++)if(l[i] && l[i]==r[i])cout<<i+1<<endl;
    return 0;
}
