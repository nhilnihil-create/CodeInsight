#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin>>s;
    int n=(int)s.length()+1;
    vector<ll> v(n+1);
    for(int i=0;i<n;i++){
        if(s[i]=='<') v[i+1]=max(v[i]+1,v[i+1]);
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='>') v[i]=max(v[i+1]+1,v[i]);
    }
    cout<<accumulate(v.begin(),v.end(),0LL)<<endl;
}