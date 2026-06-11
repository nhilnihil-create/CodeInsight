#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dans(ans) cout << std::fixed << std::setprecision(10) << ans << endl;
main()
{
    int n;
    cin>>n;
    set<int>st;
    vector<int>v(n);
    map<int,int>cnt;
    int total=0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        st.insert(x);
        v[i]=x;
        cnt[x]++;

    }
    for(auto it:st)
    {
        total+=(cnt[it]*(cnt[it]-1))/2;
    }
    for(int i=0; i<n; i++)
    {
        int x,y,ans=total;
        x=cnt[v[i]];
        ans-=(x*(x-1))/2;
        x--;
        ans+=(x*(x-1))/2;
        cout<<ans<<endl;
    }
}
/// check long long
/// check array size()

