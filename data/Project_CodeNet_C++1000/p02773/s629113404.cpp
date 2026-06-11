#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,m=0;
    string s;
    cin>>n;
    map<string,long long> ss;
    f(i,0,n){
        cin>>s;
        ss[s]++;
    }
    
    for(auto x: ss){
        m=max(m,x.second);
    }
    for(auto x:ss){
        if(x.second==m){
            cout<<x.first<<endl;
        }
    }
    
    return 0;
}
