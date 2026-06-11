#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    string s;cin>>s;
    ll k;cin>>k;
    ll ans=0;
    int c=1;
    int n=s.size();
  bool flag=true;
  for(int i=0;i<n-1;i++)if(s[i]!=s[i+1]){
    flag=false;break;
  }
  if(flag){
    cout<<n*k/2<<endl;
    return 0;
  }
    vector<int> cnt;
    for(int i=0;i<n;i++){
        if(i+1<n&&s[i]==s[i+1]) c++;
        else{
            ans+=c/2;
            cnt.push_back(c);
            c=1;
        }
    }
    ans*=k;
    if(s[0]==s[n-1]){
        ans=ans-(cnt.front()/2+cnt.back()/2-(cnt.front()+cnt.back())/2)*(k-1);
    }
    cout<<ans<<endl;
    return 0;
}