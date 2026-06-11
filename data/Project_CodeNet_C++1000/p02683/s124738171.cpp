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
#define ll long long
#define int long long
const int N = 200005;
const ll mod = 2000000011;
#define ld long double
#define PI 3.14159265358979323846
const int INF = 10000000;

void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
}

//3. Structure or classes
//3. Ends here

//1. Data structures declaration here
vector<int>c;
vector<vector<int> >a;
int n,m,x;
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
        //cout<<"\n";
    }
    return 0;
}

void solve()
{
    cin>>n>>m>>x;

    a.resize(n,vector<int>(m));
    c.resize(n);
    

    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    int all = 1<<n;

    int minCost=1e9;

    for(int mask=0;mask<all;mask++){
        vector<int>rev(m);
        int cost=0;

        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                cost+=c[i];
                for(int j=0;j<m;j++){
                    rev[j]+=a[i][j];
                }
            }
        }

        bool ok=1;
        for(int i=0;i<m;i++){
            if(rev[i]<x){
                ok=0;
                break;
            }
        }

        if(ok==1){
            minCost=min(minCost,cost);
        }
    }

    if(minCost==1e9){
        cout<<-1<<"\n";
    }
    else cout<<minCost<<"\n";

    return;

}
// how r u bro