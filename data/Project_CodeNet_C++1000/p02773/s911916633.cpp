#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int>mp;
    int maxv=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]++;
        maxv=max(maxv,mp[s]);
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        if(itr->second==maxv)cout<<itr->first<<endl;
    }
    return 0;
}