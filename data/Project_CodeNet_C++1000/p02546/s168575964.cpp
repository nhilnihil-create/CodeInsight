#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    string s;
    cin>>s;
    if(s.back()=='s')
    s+="es";
    else s+="s";
    cout<<s<<endl; 
}
