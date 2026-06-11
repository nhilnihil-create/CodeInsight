#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+5;
const int W=2019;

signed main(){

ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t=1;
//cin>>t;
while(t--){

string s;
cin>>s;
int ans=0;
int x=0;
unordered_map<int,int>m;

int h[N]={};
h[0]=1;
int j=10;
for(int i=1;i<N;i++){
    h[i]=(j)%W;
    j=(j*10)%W;
}

int rem=0;
m[0]=1;
for(int i=0;i<s.size();i++){

    rem+=((h[s.size()-i-1]*(s[i]-'0')));
    rem%=W;
    if(m.count(rem)>0)
    ans+=m[rem];

    m[rem]++;

}
cout<<ans<<endl;

}


}

