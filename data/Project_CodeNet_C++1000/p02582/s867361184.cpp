#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    vector<int>temp(3,0);
    string s; cin>>s;
    int ns = 0;
    for(int i = 0; i<3; i++){
        int prev = 0;
        if(i){
            prev = temp[i-1];
        }
        if(s[i]=='R'){
            temp[i] = prev+1;
            ns = max(ns,temp[i]);
        }
    }
    cout << ns;
    return 0;
}
