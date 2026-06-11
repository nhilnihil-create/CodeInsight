  
/*
    Bismillahir Rahmanir Raheem
    Think Twice Code Once
    author : reaziii
*/
#include<bits/stdc++.h>
#define sc(x)        scanf("%lld",&x)
#define pcase(x)     printf("Case %d: ",x++)
#define pn           printf("\n")
#define fri(f)       for(int i=0;i<f;i++)
#define frj(f)       for(int j=0;j<f;j++)
#define reset(x,e)   memset(x,e,sizeof(x))
#define all(x)       x.begin(),x.end()
#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout)
#define infi         INT_MAX
#define m_v          3000000
#define pii          pair<int,int>
#define pch          pair<char,char>
#define pll          pair<ll,ll>
#define mgraph       map<int,set<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))
#define frx(x,y)     for(int x=0;x<y;x++)
#define deb(x)       cout<<x
#define ideb(i,x)    cout<<i<<" "<<x
#define F            first
#define S            second
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
bool checkbitt(ll num,int pos);
ll setbitt(ll num,ll pos);
ll resetbitt(ll num,int pos);
 //.................___Start from here___.................//
//.................._____________________................//


int counter(int x) {
    if(x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}
 


void solve(){
    int n;
    cin>>n;
    int mask = 1<<n;
    mask--;

    int a[n+1],x[n+1][n+1],y[n+1][n+1];

    for(int u = 1 ; u <= n ; u++ ){
        cin>>a[u];
        for(int v = 1;v<=a[u];v++){
            cin>>x[u][v]>>y[u][v];
        }
    }

    int ans = 0;

    for(int i=1;i<=mask;i++){
        bool f =true;

        for(int j=1;j<=n;j++){
            if(i & (1<<(j-1))){
                for(int k=1;k<=a[j];k++){
                    if(y[j][k]^checkbitt(i,(x[j][k]-1))) f = false;
                }
            }
        }

        if(f) ans = max(ans,counter(i));
    }

    cout<<ans<<endl;

}


int main(){
    // input;
    // output;

    solve();
}






bool checkbitt(ll num,int pos){
    return (num>>pos) & 1;
}

ll setbitt(ll num,ll pos){
    return (1<<pos) | num;
}

ll resetbitt(ll num,int pos){
    if(!checkbitt(num,pos)) {
        return num;
    }
    else{
        return (1<<pos)^num;
    }
}



