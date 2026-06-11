#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();

    vector<long long> val(2019,0);
    long long fac=1;
    long long cur=0;
    ++val[cur];

    for(int i=0;i<n;++i){
        long long add=s[n-1-i]-'0';
        cur=(cur+add*fac)%2019;
        fac=(10*fac)%2019;
        ++val[cur];
    }

    long long res=0;
    for(int i=0;i<2019;++i){
        res+=val[i]*(val[i]-1)/2;
    }

    cout<<res<<endl;
}