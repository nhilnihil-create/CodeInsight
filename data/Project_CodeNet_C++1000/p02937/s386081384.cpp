#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    vector<vector<int>>chr(26);
    for(int i=0;i<s.size();i++)chr[s[i]-'a'].push_back(i);
    long long x=0;
    int p=-1;
    for(int i=0;i<t.size();i++){
        if(chr[t[i]-'a'].size()==0){
            cout<<"-1"<<endl;
            return 0;
        }
        if(p>=chr[t[i]-'a'].back()){
            x+=chr[t[i]-'a'][0]+s.size()-p;
            p=chr[t[i]-'a'][0];
        }
        else{
            x+=*upper_bound(chr[t[i]-'a'].begin(),chr[t[i]-'a'].end(),p)-p;
            p=*upper_bound(chr[t[i]-'a'].begin(),chr[t[i]-'a'].end(),p);
        }
    }
    cout<<x<<endl;
    return 0;
}