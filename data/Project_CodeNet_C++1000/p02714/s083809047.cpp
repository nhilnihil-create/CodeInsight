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
const int N = 4005;
const ll mod = 1e9+7;
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
    int n;
    cin>>n;
    string s;
    cin>>s;

    int ans1=0,ans2=0;

    int r=0,b=0,g=0;

    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            ans1+=g*b;
            r++;
        }
        else if(s[i]=='B'){
            ans1+=r*g;
            b++;
        }
        else{
            ans1+=r*b;
            g++;
        }
    }

    for(int i=0;i<=n-3;i++){
        for(int j=i+2;j<n;j+=2){
            if(s[i]!=s[j] && s[i]!=s[(i+j)/2] && s[j]!=s[(i+j)/2]){
                ans2++;
            }
        }
    }
    
    cout<<ans1-ans2<<"\n";

    return;
}
// how r u bro