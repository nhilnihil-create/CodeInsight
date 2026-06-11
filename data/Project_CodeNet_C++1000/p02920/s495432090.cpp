#include<bits/stdc++.h>
using namespace std;
/*
#ifndef ONLINE_JUDGE
    #define cin f
    #define cout g
    ifstream cin("a.in");
    ofstream cout("a.out");
#endif
*/
int n,v[1<<19];
bool viz[1<<19];
vector <int> Q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int N=1<<n;
    for(int i=1;i<=N;++i) cin>>v[i];
    sort(v+1,v+N+1);
    reverse(v+1,v+N+1);
    Q.push_back(v[1]);
    viz[1]=1;
    for(int i=0;i<n;++i)
    {
        int ind=2;
        for(int j=0;j<(1<<i);++j)
        {
            while(ind<=N&&(v[ind]>=Q[j]||viz[ind])) ind++;
            if(ind==N+1)
            {
                cout<<"No";
                return 0;
            }
            viz[ind]=1;
            Q.push_back(v[ind]);
        }
        sort(Q.begin(),Q.end());
        reverse(Q.begin(),Q.end());
    }
    cout<<"Yes";
    return 0;
}
