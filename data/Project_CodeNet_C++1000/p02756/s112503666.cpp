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
    string s;
    cin>>s;

    int q;
    cin>>q;

    int cnt=0;

    string beg,en;

    while(q--){
        int num;
        cin>>num;
        if(num==1){
            cnt++;
        }
        else{
            int n1;
            cin>>n1;

            char ch;
            cin>>ch;

            if(n1==1){
                if(cnt%2==0){
                    beg+=ch;
                }
                else{
                    en+=ch;
                }
            }
            else{

                if(cnt%2==0){
                    en+=ch;
                }
                else{
                    beg+=ch;
                }

            }



        }
    }

    if(cnt%2==0){
        reverse(beg.begin(),beg.end());
        cout<<beg;
        cout<<s<<en;
    }
    else{
        reverse(en.begin(),en.end());
        cout<<en;
        reverse(s.begin(),s.end());
        cout<<s<<beg;
    }
    return;
}
// how r u bro