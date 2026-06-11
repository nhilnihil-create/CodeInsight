#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0;i<(ll)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;
const ll INF = 1e9;
int main(){
    fast_io
    
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> dist(n+1, INF);
    vector<int> MostLeft(n+1, INF);
    dist[n]=0;
    MostLeft[0]=n;
    int Next = n-1;
    int Left = n;
    int timer=0;
    while(true){
        timer++;
        int newLeft = Left;
        while(Next>= Left-m && Next>=0){
            if(s[Next]=='0'){
                dist[Next]=timer;
                newLeft=Next;
            }
            Next--;
        }
        if(newLeft==Left){
            cout<<-1<<endl;
            return 0;
        }
        Left=newLeft;
        MostLeft[timer]=Left;
        if(Next<0)break;
    }
    timer=dist[0];
    //rep(i,n+1) cerr<<dist[i]<<endl;

    vector<int> ans;
    int now=0;
    while(timer>=1){
        timer--;
        ans.push_back(MostLeft[timer]-now);
        now=MostLeft[timer];
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i+1!=ans.size()) cout<<" ";
    }
    cout<<endl;
    return 0;
}