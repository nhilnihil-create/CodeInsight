#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int acs=0,was=0;
    vector<bool> flag(n,false);
    vector<int> wa(n,0);
    for(int i=0;i<m;i++){
        int p;
        string s;
        cin>>p;
        cin>>s;
        p--;
        if(s=="AC"){
            if(!flag[p]){
                flag[p]=true;
                acs++;
                was+=wa[p];
            }
        }else{
            if(!flag[p]){
                wa[p]++;
            }
        }
    }
    cout<<acs<<" "<<was<<"\n";
    return(0);
}