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
    int N;cin>>N;
    int a;
    bool flag=true;
    rep(i,N){
        cin>>a;
        if(a%2==0){
            if(a%3==0 || a%5==0){
                continue;
            }else{
                flag=false;
                break;
            }
        }
    }
    if(flag){
        cout<<"APPROVED"<<endl;
    }else{
        cout<<"DENIED"<<endl;
    }
}