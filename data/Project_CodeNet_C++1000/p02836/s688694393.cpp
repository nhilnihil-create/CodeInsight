#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=1;i<=n;i++)
#define endl   "\n"







int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string user;
    cin>>user;
    int i=0;
    int j=user.size()-1;
    int count=0;
    while(i<j)
    {
        if(user[i]!=user[j]) {
            count++;
        }
        
        i++;
        j--;

    }
    cout<<count<<endl;











}