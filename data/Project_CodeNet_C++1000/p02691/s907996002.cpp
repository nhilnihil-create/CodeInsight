#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<long long,long long> mp;
    long long res=0;
    for(int i=0;i<n;++i){
        long long a;
        cin>>a;
        res+=mp[i+1-a];
        ++mp[i+1+a];
    }

    cout<<res<<endl;
}