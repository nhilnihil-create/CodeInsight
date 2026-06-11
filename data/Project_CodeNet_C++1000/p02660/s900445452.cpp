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
    int ans=0;
    if(n==1){
        cout<<"0\n";return;
    }
    for(int i=2;i*i<=n;i++){
        int cnt=0;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        ans += (sqrtf(1+8*cnt)-1)/2;
    }
    if(n!=1){
        ans++;
    }
    cout<<ans;
    return;
}