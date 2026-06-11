#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    /*
    int a,b;
    cin>>a>>b;
    if(a+b==3)
    {
        cout<<3<<endl;
    }
    else if(a+b==4)
    {
        cout<<2<<endl;
    }
    else
    {
        cout<<1<<endl;
    }
    */
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    string s_t;
    for(int i=0;i<n;i++)
    {   
        s_t.push_back(s[i]);
        s_t.push_back(t[i]);
    }   
    cout<<s_t<<endl;
    
    return 0;
}