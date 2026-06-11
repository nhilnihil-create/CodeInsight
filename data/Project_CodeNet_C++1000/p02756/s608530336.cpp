#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
    string s,fro="",bac="";
    int q,now=1;
    cin>>s>>q;
    rep(i,q){
        int t;
        cin>>t;
        if(t==1){
            if(now==1) now--;
            else now++;
        }
        else{
            int f;
            char k;
            cin>>f>>k;
            if(f==1){
                if(now==1){
                    fro=k+fro;
                }
                else{
                    bac=bac+k;
                }
            }
            else{
                if(now==1){
                    bac=bac+k;
                }
                else{
                    fro=k+fro;
                }
            }
        }
    }
    s=fro+s+bac;
    if(now==0) reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}