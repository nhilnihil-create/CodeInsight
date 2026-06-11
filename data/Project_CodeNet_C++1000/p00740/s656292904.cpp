#include <iostream>
#include <vector>

using namespace std;

int game (int n, int p)
{
    int a[n]={0};
    bool ok;
    for (int i=0; i<n; i++)
    {
        if (p!=0)
        {
            a[i]++; p--;
            if (p==0)
            {
                ok=true;
                for (int j=0; j<n; j++)
                {
                    if (i==j) continue;
                    if (a[j]!=0) ok=false;
                }
                if (ok) return i;
            }
        }
        else { p+=a[i]; a[i]=0; }
        if (i==n-1) i=-1;
    }
}

int main()
{
    int n, p;
    vector<int> ans;
    while (1)
    {
        cin>>n>>p;
        if (n==0 && p==0) break;
        ans.push_back(game(n,p));
    }
    for (int i=0; i<ans.size(); i++) cout<<ans[i]<<'\n';
    return 0;
}

