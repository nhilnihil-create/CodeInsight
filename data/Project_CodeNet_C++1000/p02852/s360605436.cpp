#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<int>a,b;
    map<int,int>c;
    for(int i=0;i<=n;++i){
        if(s[i]=='0'){
            a.push_back(i);
            c[i]=1;
        }
    }
    int now=n;
    while(now>0){
        int l=lower_bound(a.begin(),a.end(),now-m)-a.begin();
        if(a[l]==now){
            cout<<-1<<endl;
            return 0;
        }
        b.push_back(now-a[l]);
        now=a[l];
    }
    reverse(b.begin(),b.end());
    for(int i=0;i<b.size();++i){
        if(i!=b.size()-1)cout<<b[i]<<" ";
        else cout<<b[i]<<endl;
    }
}