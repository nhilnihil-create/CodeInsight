#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string slim;
    cin>>slim;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(i==0) {
            count++;
            continue;

        }
        if(slim[i]==slim[i-1]) continue;
        else count++;


    }
    cout<<count<<endl;





}