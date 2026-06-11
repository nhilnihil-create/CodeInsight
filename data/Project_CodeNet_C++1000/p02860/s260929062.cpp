#include <bits/stdc++.h>
using namespace std;
#define   nl   <<'\n'
#define   pi   acos(-1.0);
#define   ll   long long
#define   pb   push_back
#define   eb   emplace_back
#define   tc   int t; cin>>t; while(t--)
#define   fio  ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2) cout<<"No\n";
    else 
    {
        for(int i=0; i<n/2; i++)
        {
            if(s[i]!=s[n/2+i])
            {
                cout<<"No\n";
                return 0;
            }
        }
        cout<<"Yes\n";
    }
}  