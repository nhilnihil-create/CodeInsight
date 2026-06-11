#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n-1;++i){
        if(s[i]!=s[i+1]) ++cnt;
    }

    cout<<n-1-max(cnt-2*k,0)<<endl;
}