#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
#define pi 3.141592653589793
using namespace std;
int sdkys(int a,int b){
    if(b==0) return a;
    return sdkys(b,a%b);
}
int sskbs(int a,int b){
    return a*b/sdkys(a,b);
}
int sosu(int a){
    if(a==2){
        return 1;
    }
    for(int i=2;i<sqrt(a)+1;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}
vector<int> aa,ab;
int n,m,cnt=0,ans=0;
pair<int,char> pp[220000];
string s,sa[220000];
char ch;
queue<int> que;
signed main(){
    cin>>n>>m;
    rep(i,m){
        cin>>pp[i].first>>pp[i].second;
    }
    rep(i,1000){
        s=to_string(i);
        rep(j,m){
            if(s[pp[j].first-1]!=pp[j].second){
                goto no;
            }
        }
        if(i>=pow(10,n-1)){
            cout<<i<<endl;
            return 0;
        }elif(i==0&&n==1){
            cout<<0<<endl;
            return 0;
        }
        no:;
    }
    cout<<-1<<endl;
}