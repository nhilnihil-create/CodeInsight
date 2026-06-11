#include<bits/stdc++.h>
using namespace std;

void solve(){

    // A * B + C = N
    int n; cin>>n;
    //int a,b,c;
    int count=0;
    
    for(int i=1;i<n;i++)
    {
        count+=(n-1)/i;
    }

    cout<<count;
}

int main()
{
    solve();
}