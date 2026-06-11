#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    vector<long long int> v[26];
    for(int i=0;i<(int)s.length();i++)v[(int)(s[i]-'a')].push_back(i);
    long long int ans=0;
    long long int tmp=0;
    int start=0;
    if(s[0]==t[0])start=1;
    for(int i=start;i<(int)t.length();i++){
        if(v[(int)(t[i]-'a')].size()==0){
            cout << -1;
            return 0;
        }
        int u = upper_bound(v[(int)(t[i]-'a')].begin(),v[(int)(t[i]-'a')].end(),tmp)-v[(int)(t[i]-'a')].begin();
        if(u<(int)v[(int)(t[i]-'a')].size()){
            ans+=v[(int)(t[i]-'a')].at(u)-tmp;
            tmp=v[(int)(t[i]-'a')].at(u);
        }
        else{
            ans+=(long long int)s.length()-tmp+v[(int)(t[i]-'a')].at(0);
            tmp=v[(int)(t[i]-'a')].at(0);
        }
    }
    cout << ans+1;
}