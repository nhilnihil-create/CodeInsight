#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s,s1;
    cin>>s>>s1;
    bool reshenie=true;
    if(s1.size()-s.size()!=1)
        reshenie=false;
    for(int i=0;i<(int)s.size();i++){
        if(s.at(i)!=s1.at(i))
            reshenie=false;
    }
    if(reshenie==false){
        cout<<"No";
    }
    else
        cout<<"Yes";
}
