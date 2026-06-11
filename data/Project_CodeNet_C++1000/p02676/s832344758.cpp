#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int N=200000;

void Run()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int a[N];
set<int>v;
int main()
{
    Run();
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.size()>n)
    {
    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }
    cout<<"...";
    }

    else
        cout<<s;
}
