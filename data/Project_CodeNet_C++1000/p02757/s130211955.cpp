#include <bits/stdc++.h>
using namespace std;
int N,sum=0,x=1,P,a;
long long ans=0;
string S;
int main(){
    cin>>N>>P>>S;
    unordered_map<int,long long> mp;
    for(int i=0;i<N;i++){
        if(P==2 && (S.at(N-i-1)-'0')%2==0){ans+=N-i;}
        if(P==5 && (S.at(N-i-1)-'0')%5==0){ans+=N-i;}
        a=(S.at(N-1-i)-'0');
        sum+=a*x;
        sum%=P;
        mp[sum]++;
        x*=10;
        x%=P;
    }
    if(10%P==0){cout<<ans<<endl;}
    else{
        ans=mp[0];
        for(int i=0;i<P;i++){ans+=mp[i]*(mp[i]-1)/2;}
        cout<<ans<<endl;
    }
}