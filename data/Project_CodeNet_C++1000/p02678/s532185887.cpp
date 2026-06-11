/*
        karmany evadhikaras te
        ma phalesu kadacana 
        ma karma-phala-hetur bhur
        ma re sango'stv akarmani (B.G.-2.47)
 
Translation:
        Lord Krsna to Arjuna.
You have a right to perform your prescribed duty, 
but you are not entitled to the fruits of action. 
Never consider yourself the cause of the results of your activities, 
and never be attached to not doing your duty.    
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N = 1000005;
#define ld long double
#define PI 3.14159265358979323846
const int INF = 1e9+7;

void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(12);
}

//3. Structure or classes
//3. Ends here

//1. Data structures declaration here
//1. Ends here


//2. Extra Functions here
//2. Ends here


void solve();
int32_t main()
{
    flash();
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

void solve()
{
    
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int>q;
    vector<array<int,2>>vec(n+1,{INF,INF});


    vec[1][0]=0;
    vec[1][1]=0;
    bool vis[n+1]={0};

    q.push(1);
    while(!q.empty()){
        int src = q.front();
        vis[src]=1;
        q.pop();
        for(auto j:adj[src]){
            if(vis[j]==1)continue;
            if(vec[j][1]>vec[src][1]+1){
                vec[j][0] = src;
                vec[j][1] = vec[src][1]+1;
                q.push(j);
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(vec[i][0]==INF){
            cout<<"No\n";
        }
    }

    cout<<"Yes\n";

    for(int i=2;i<=n;i++){
        cout<<vec[i][0]<<"\n";
    }

    return;
}