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
const int X = 10000000;

void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(20);
}

//3. Structure or classes
//3. Ends here

//1. Data structures declaration here
vector<int>Next;
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
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}

void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int arr[n+1]={0};
    for(int i=0;i<n;i++){
        if(s[i]=='<'){
            arr[i+1]=arr[i]+1;
        }
    }


    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='>'){
            if(arr[i]<arr[i+1]+1){
                arr[i]=arr[i+1]+1;
            }
        }
    }


    int ans=0;
    for(int i=0;i<=n;i++){
        ans+=arr[i];
    }
    cout<<ans;
    return;
}