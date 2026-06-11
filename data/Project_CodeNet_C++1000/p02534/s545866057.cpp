#include<bits/stdc++.h>
using namespace std;

#define sync {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define ll long long int
#define mod 1000000007


int s;

void solve()
{
    cin>>s;
    
    string ans = "";
    
    for(int i =0;i<s;i++)
        ans +="ACL";
    
    cout<<ans;
    
}

int main()
{
    sync;
    int t = 1;
   // cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}





