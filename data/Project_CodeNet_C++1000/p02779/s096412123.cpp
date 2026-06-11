#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    set<int> s;
    int n,a;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a;
        s.insert(a);
    }
    if(n==s.size())
    
        cout<<"YES"<<endl;
    
    else
    
        cout<<"NO"<<endl;
    
    return 0;
}