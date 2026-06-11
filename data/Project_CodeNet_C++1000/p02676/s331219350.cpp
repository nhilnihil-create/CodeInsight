#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    if(s.size()>k){
        for(int i=0;i<k;++i){
            cout<<s[i];
        }
        cout<<"..."<<endl;
    }
    else{
        cout<<s<<endl;
    }
    return 0;
}