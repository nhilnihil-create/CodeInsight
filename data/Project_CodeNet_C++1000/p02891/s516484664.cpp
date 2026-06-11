#include<iostream>
using namespace std;
using ll = long long;

int main(){
    string s;
    ll k;
    cin>>s>>k;
    ll c=1,l=1,ans=0,n=s.size();
    bool f=true;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) c++;
        else{
            if(f){
                f=false;
                l=c;
            }
            ans+=c/2;
            c=1;
        }
    }
    ll r=c;
    ans+=c/2;
    ans*=k;
    if(c==n) ans=c*k/2;
    else if(s[0]==s[n-1]) ans-=(r/2+l/2-(r+l)/2)*(k-1);
    cout<<ans<<endl;
}