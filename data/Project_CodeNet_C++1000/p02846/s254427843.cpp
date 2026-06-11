#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=2e9;
const ll MOD=1e9+7;

ll T1,T2;
ll A1,A2;
ll B1,B2;

int main(){
    cin>>T1>>T2;
    cin>>A1>>A2;
    cin>>B1>>B2;
    if(A1>B1){
        swap(A1,B1);swap(A2,B2);
    }
    ll P=T1*(A1-B1),Q=T2*(A2-B2);
    if(P+Q<0){
        cout<<0<<endl;
        return 0;
    }else if(P+Q==0){
        cout<<"infinity"<<endl;
        return 0;
    }
    ll T=(-P)%(P+Q);
    if(T==0){
        cout<<2*((-P)/(P+Q))<<endl;
    }else{
        cout<<2*((-P)/(P+Q))+1<<endl;
    }
    return 0;
}