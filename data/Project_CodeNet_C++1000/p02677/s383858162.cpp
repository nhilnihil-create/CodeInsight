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
    
    ld a,b,h,m;
    cin>>a>>b>>h>>m;
    ld theta = abs(((h*30)+((0.5)*m))-(6*m));
    theta = min(theta,360-theta);
    theta = (PI*theta)/180.0;
    //cout<<theta<<" "<<cos(theta)<<"\n";
    ld ans =sqrt( (a*a) + (b*b) - (2*a*b*cos(theta)) );
    cout<<ans;
    return;
}