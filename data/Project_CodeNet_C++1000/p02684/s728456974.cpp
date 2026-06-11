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
    int n;
    int k;
    cin>>n>>k;
    Next.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>Next[i];
    }

    long long slo = Next[1];
    long long fas = Next[Next[1]];

    vector<int>repo1;
    vector<int>repo2;


    while(slo!=fas){
        repo1.push_back(slo);
        slo = Next[slo];
        fas = Next[Next[fas]];
    }

    repo2.push_back(slo);
    int lambda=1;
    slo = Next[slo];
    while(slo!=fas){
        repo2.push_back(slo);
        slo = Next[slo];
        lambda++;
    }

/*
    
    for(auto i:repo1){
        cout<<i<<" ";
    }

    cout<<"\n";

    for(auto i:repo2){
        cout<<i<<" ";
    }
*/
    k--;
    if(k<repo1.size()){
        cout<<repo1[k];
    }
    else{
        k-=repo1.size();
        k%=repo2.size();
        cout<<repo2[k];
    }

    return;
}