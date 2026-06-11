#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 
ll cnt[1000010];

void pre(ll n){
    cnt[0]=0;
    for(ll i=1;i<=n;i++){
        ll add = 0;
        ll x = i;
        while(x%2==0)x/=2,add++;
        cnt[i] = cnt[i-1]+add;
    }
}

ll coff[3]={};
int  A(int x){
    if(x>=0)return x;
    else return -x;
}

int main(void){
    ll n;
    string s;
    cin>>n>>s;
    vector<int>a;
    for(int i=0;i<n-1;i++){
        int x = s[i]-'0';
        int y = s[i+1]-'0';
        a.push_back(A(x-y));
    }
    pre(n);
    for(ll i=0;i<a.size();i++){
        ll v = cnt[a.size()-1] -cnt[i] - cnt[a.size()-1-i];
        if(v==0)coff[a[i]]+=1;
    }
    //cout<<coff[1]<<endl;
    if(coff[1]%2==1){
        cout<<1<<endl;
        return 0;
    }
    else{
        if(coff[1]!=0)cout<<0<<endl;
        else{
            for(int i=0;i<a.size();i++){
                a[i]=a[i]/2;
            }
            coff[0]=0;
            coff[1]=0;
            coff[2]=0;
            for(ll i=0;i<a.size();i++){
                ll v = cnt[a.size()-1] -cnt[i] - cnt[a.size()-1-i];
                if(v==0)coff[a[i]]+=1;
            }
            if(coff[1]%2==1)cout<<2<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}