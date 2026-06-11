#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int>safe;
    vector<int>out;
    for(int i=0;i<=n;i++){
        if(s[i]=='0')safe.push_back(i);
        else out.push_back(i);
    }
    int p=n;
    vector<int>move;
    while(true){
        if(p<=m){
            move.push_back(p);
            break;
        }
        int x=*lower_bound(safe.begin(),safe.end(),p-m);
        if(x==p){
            cout<<"-1"<<endl;
            return 0;
        }
        move.push_back(p-x);
        p=x;
    }
    for(int i=move.size()-1;i>=0;i--)cout<<move[i]<<endl;
    return 0;
}