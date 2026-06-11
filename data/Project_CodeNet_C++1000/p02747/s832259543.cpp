#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    bool ok=true;
    int n=s.size();
    for(int i=0; i<n; i+=2){
        if(s.substr(i,2)!="hi")ok=false;
    }
    if(n%2==1)ok=false;
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}