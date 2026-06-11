#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX/10
#define rep(i,n) for(int i=0;i<n;i++)
#define krep(i,k,n,m) for(int i=k;i<n;i+=m)
#define erep(i,k,n) for(int i=k;i<n;i++)
#define mod 1000000007
//最大公約数
int gcd(int s,int b){
    if(b==0)return s;
    return gcd(b,s%b);
}
signed main(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    string s;
    cin>>s;
    if(c<d){
        for(int i=a-1;i<d-1;i++){
            if(s[i]=='#'&&s[i+1]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }
    else{
        for(int i=a-1;i<c-1;i++){
            if(s[i]=='#'&&s[i+1]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        for(int i=b-1;i<d;i++){
            if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.'){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
    }
}
