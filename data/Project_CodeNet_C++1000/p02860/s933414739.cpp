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
    int N;string s;cin>>N>>s;
    string test="";
    bool flag=true;
    if(N%2==1){
        cout<<"No"<<endl;
        return 0;
    }else{
        for(int i=0;i<N/2;i++){
            test+=s.at(i);
        }
        for(int i=N/2;i<N;i++){
            if(test.at(i-N/2)!=s.at(i)){
                flag=false;
                break;
            }
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}