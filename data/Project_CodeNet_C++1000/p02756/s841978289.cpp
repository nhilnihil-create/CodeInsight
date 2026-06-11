#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
cin.tie(NULL);

    string s;
    int n;
    cin>>s>>n;
    
    bool r = 1;
    int cnt = 0;
    vector<char> v[2];
    for(int i = 0; i < n; i++){
        int t;
        cin>>t;
        if(t==1){
            r = !r;
            cnt++;
        } else{
            int tt;cin>>tt;
            char c;
            cin>>c;
            if(tt==1){
                if(r) v[0].push_back(c);
                else v[1].push_back(c);
            } else {
                if(r) v[1].push_back(c);
                else v[0].push_back(c);
            }
        }
    }
    string res;
    for(int i = (int)v[0].size()-1; i>=0; i--){
        res+=v[0][i];
    }
    res+=s;
    for(int i = 0; i < (int)v[1].size(); i++){
        res+=v[1][i];
    }
    if(cnt%2) reverse(res.begin(),res.end());
    cout<<res;
}
