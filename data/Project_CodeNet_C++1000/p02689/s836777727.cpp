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
    int n,m;
    cin>>n>>m;
    int h[n+1];

    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    vector<int>maxh(n+1,0);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        maxh[x]=max(maxh[x],h[y]);
        maxh[y]=max(maxh[y],h[x]);   
    }

    int cnt=0;

    for(int i=1;i<=n;i++){
        if(h[i]>maxh[i])cnt++;
    }

    cout<<cnt<<"\n";
    return;

}
// how r u bro