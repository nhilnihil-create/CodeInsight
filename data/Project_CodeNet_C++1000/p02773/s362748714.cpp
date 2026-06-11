#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string,int> ma;
    int vmax=0;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        if(ma.find(a)==ma.end()){
            ma[a]=1;
        }else{
            ma[a]++;
        }
        vmax=max(vmax,ma[a]);
    }
    priority_queue<string,vector<string>,greater<string>> ans;
    for(auto it=ma.begin();it!=ma.end();it++){
        if(it->second==vmax){
            ans.push(it->first);
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<"\n";
        ans.pop();
    }
    return(0);
}