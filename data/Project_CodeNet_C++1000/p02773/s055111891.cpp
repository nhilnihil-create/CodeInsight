#include<bits/stdc++.h>
using  namespace  std;

map<string,long long> mp;
int main() {

    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    long long n;
    cin>>n;

    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        mp[name]++;
    }

    long long max = 0;
    for(auto i=mp.begin();i!=mp.end();i++){
        if(i->second>max){
            max = i->second;
        }
    }

    for(auto i=mp.begin();i!=mp.end();i++){
        if(i->second==max){
            cout<<i->first<<"\n";
        }
    }




    return 0;
}