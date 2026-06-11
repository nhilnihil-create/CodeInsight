#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,long long>m;
    string s,t,u;
    long long a,b;
    cin>>s>>t;
    cin>>a>>b;
    cin>>u;
    m[s]=a;
    m[t]=b;
    m[u]--;
    cout<<m[s]<<" "<<m[t]<<endl;
    return 0;    
}