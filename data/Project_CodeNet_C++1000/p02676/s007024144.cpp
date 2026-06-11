#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.length()<=n)
    cout<<s<<endl;
    else
    {
        cout<<s.substr(0,n)+string(3,'.');
    }
    

    
}