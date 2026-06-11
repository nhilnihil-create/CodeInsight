#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    long long a[500005]={};
    long long b[500005]={};
    long long ans=0;
    cin>>s;
    for(int i=1;i<=s.size();i++){
        if(s[i-1]=='<'){
            a[i]=a[i-1]+1;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='>'){
            b[i]=b[i+1]+1;
        }
    }
    for(int i=0;i<=s.size();i++){
        ans+=max(a[i],b[i]);
    }
    cout<<ans<<endl;
    return(0);
}