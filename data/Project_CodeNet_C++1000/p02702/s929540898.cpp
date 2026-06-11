#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    string s;
    cin>>s;

    map<int,int> m;
    m[0]++;
    int mod=2019;

    int r=0;
    int k=1;

    for(int i=s.size()-1;i>=0;i--){
        r+=k*((int)s[i]-'0');
        r%=mod;
        //cout<<r<<endl;
        m[r]++;

        k*=10;
        k%=mod;
    }

    long long ans=0;
    for(auto p:m){
        int x=p.second;
        if(x>=2){
            //cout<<p.first<<endl;
            ans+=(x*(x-1)/2);
        }
    }

    cout<<ans<<endl;
    return 0;
}