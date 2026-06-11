#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s,t;
    cin>>s>>t;
    long long int cnt=0;
    for(unsigned int i=0;i<s.size();i++){
        if(s.at(i)!=t.at(i))
            cnt++;
    }
    cout<<cnt;
}
