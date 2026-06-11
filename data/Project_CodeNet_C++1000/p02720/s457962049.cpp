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
const int N = 1005;
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
string next(string s){
    reverse(s.begin(),s.end());

    string s2=s;
    int j;
    for(j=0;j<s.length();j++){
        if(s2[j]=='9'){
            s2[j]='0';
        }
        else break;
    }

    if(s.length()==j){
        s=s2;
        s+='1';
        reverse(s.begin(),s.end());
        return s;
    }

    if(s.length()==1){
        int c1=s[0]-'0';
        s[0]=(c1+1)+'0';
    }

    for(j=0;j<s.length()-1;j++){
        int c1 = (s[j]-'0');
        int c2 = (s[j+1]-'0');
        if(abs(c1-c2)<=1)continue;
        else if(abs(c1+1-c2)<=1){
            //doing part 1
            c1++;
            s[j]=c1+'0';
            s[j+1]=c2+'0';
        }
        else{
            c1=c2;
            c2++;
            s[j+1]=c2+'0';
            s[j]=c1+'0';
        }
    }

    reverse(s.begin(),s.end());
    return s;
}
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
    
    int k;
    cin>>k;

    queue<int>q;

    for(int i=1;i<=9;i++)q.push(i);

    for(int i=0;i<k-1;i++){
        int d = q.front();
        q.pop();

        if(d%10!=0){
            q.push(10*d+(d%10)-1);
        }
        q.push(10*d+(d%10));
        if(d%10!=9){
            q.push(10*d+(d%10)+1);
        }
    }

    cout<<q.front();

    return;
}
// how r u bro