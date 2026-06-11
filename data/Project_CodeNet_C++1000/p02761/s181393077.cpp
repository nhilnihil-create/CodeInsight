#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forN(i, n) for(int i = 0; i <n ; ++i)
#define endl "\n"
#define noob (main)
typedef long long ll;
using namespace  std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 2e5 +5 ;
int n,m,s,c,num[4];

int noob(){
    cin>>n>>m;
    fastIO
    memset(num,-1,sizeof num);
    while(m--){
        cin>>s>>c;
        if(num[s]!=-1 && num[s]!=c){
            cout<<-1;
            return 0;
        }
        num[s] = c;
    }
    if(n>1 && !num[1]){
        cout<<-1;
        return 0;
    }
    if(n==1 && num[1] ==-1){
        cout<<0;
        return 0;
    }
    for(int i =1 ; i<=n;i++){
        if(i==1 &&num[i]==-1)cout<<1;
        else if (num[i]==-1)cout<<0;
        else cout<<num[i];
    }
}

