#include <iostream>
using namespace std;
int n,a[240001],ans;
string s,t;
int f(string s){
    int S=(s[0]-'0')*100000+(s[1]-'0')*10000+(s[3]-'0')*1000+(s[4]-'0')*100+(s[6]-'0')*10+(s[7]-'0');
    return S;
}
int main(void){
    while(1){
    cin>>n;
    if(n==0)return 0;
    for(int i=0;i<=240000;i++)a[i]=0;
    for(int i=0;i<n;i++){
        cin>>s>>t;
        //cout<<f(s)<<endl;
        a[f(s)]+=1;
        a[f(t)]+=-1;
    }
    ans=a[0];
    for(int i=0;i<240000;i++){
        a[i+1]+=a[i];
        ans=max(ans,a[i+1]);
    }
    cout<<ans<<endl;
    }
}

