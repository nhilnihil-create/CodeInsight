#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    bool c[n+1]={false};
    int k,tmp,s[n+1]={0};
    if(n>1)s[1]=1;else s[1]=0;
    bool flag=true;
    for(int i=0;i<m;i++){
        cin>>k>>tmp;
        if(k==1){
            if(n>1&&tmp==0){
                flag=false;
            }else{
                if(!c[k]){
                    s[1]=tmp;
                    c[1]=true;
                }else{
                    if(s[1]!=tmp)flag=false;
                }
            }
        }else{
            if(!c[k]){
                s[k]=tmp;
                c[k]=true;
            }else{
                if(s[k]!=tmp)flag=false;
            }
        }
    }
    if(flag){
        for(int i=1;i<=n;i++)cout<<s[i];
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}