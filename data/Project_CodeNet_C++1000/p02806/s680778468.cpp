#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
#define PB push_back
#define MP make_pairA
#define REP(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n;
    string s[55];
    int t[55];
    cin>>n;
    REP(i,n)cin>>s[i]>>t[i];
    string x;
    cin>>x;
    bool f=false;
    int cnt=0;
    REP(i,n)
    {
        if(f)cnt+=t[i];
        if(x==s[i])f=true;
    }
    cout<<cnt<<endl;
}