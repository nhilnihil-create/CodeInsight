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
    int n;
    cin>>n;
    bool rep[N]={0};
    bool vis[N]={0};

    set<int>st;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(st.find(x)==st.end())st.insert(x);
        else rep[x]=1;
    }

    int ans=0;

    for(auto i:st){
        if(vis[i]==1)continue;
        for(int j=2*i;j<N;j+=i){
            vis[j]=1;
        }
        ans += (!rep[i] && !vis[i]);
    }

    cout<<ans;


    return;
}