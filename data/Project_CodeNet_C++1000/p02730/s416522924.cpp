#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    string s;cin>>s;
    bool flag=true;
    int N=s.size();
    int k=N-1;
    for(int i=0;i<N;i++){
        if(s.at(i)!=s.at(k)){
            flag=false;
            break;
        }
        k--;
    }
    int n=(N-1)/2;
    k=n-1;
    for(int i=0;i<n;i++){
        
        if(s.at(i)!=s.at(k)){
            flag=false;
            break;
        }
        k--;
    }
    n=(N+3)/2;
    k=N-1;
    for(int i=n-1;i<N;i++){
        if(s.at(i)!=s.at(k)){
            flag=false;
            break;
        }
        k--;
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}