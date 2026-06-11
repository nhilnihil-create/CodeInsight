#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.rbegin(),v.rend()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define ff first
#define sc second
typedef long long ll;
using namespace std;

int main()
{
    int n,i,j,val=0,cost=0,ans=0;
    string s;
    cin>>n;
    cin>>s;
    queue<char>q;
    char p='&';
    for(i=0;i<n;i++)
    {
        if(s[i]!=p)
        {
            q.push(s[i]);
            p=s[i];
        }
    }
    cout<<q.size()<<endl;
    return 0;
}
