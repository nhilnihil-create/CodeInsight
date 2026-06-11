//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll n,k,i,cnt=0;
    string t;
    cin>>n>>t;
    for(i=0;i<n-2;i++)
    {
        if(t[i]=='A'&&t[i+1]=='B'&&t[i+2]=='C') cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}



