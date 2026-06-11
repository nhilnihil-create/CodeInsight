
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
    bool flag=false;
    for(int i=1;i<=9;i++){
        int a=N/i;
        if(a<=9 && a>0 && N%i==0){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
