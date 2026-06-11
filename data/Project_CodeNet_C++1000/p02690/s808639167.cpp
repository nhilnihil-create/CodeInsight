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
struct Value{
    int val = 1e9+7;
};
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
    int x;
    cin>>x;
    map<int,Value>mp;
    map<int,int>rev;
    for(int i=-1000;i<=1000;i++){
        int a = i*i*i*i*i;
        mp[a].val=i;
    }
    for(auto i:mp){
        if(mp[i.first+x].val!=1e9+7){
           cout<<mp[i.first+x].val<<" "<<mp[i.first].val<<"\n";
           return;
        }
        else{
            mp.erase(i.first+x);
        }
    }
    cout<<"-1";
    return;

}
// how r u bro