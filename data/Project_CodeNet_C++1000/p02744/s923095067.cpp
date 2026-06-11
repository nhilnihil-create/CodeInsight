#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int lli;
#define tc int t;cin>>t;while(t--)
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vll vector<lli>


int n;

void dfs(string s,char mx)
{
    if(s.length()==n)
    {
        cout<<s<<"\n";
        return;
    }
    for(char c='a';c<=mx;c++)
    {
        if(c==mx)
            dfs(s+c,mx+1);
        else
            dfs(s+c,mx);
    }

}

int main() {
   cin>>n;
   dfs("",'a');
}
