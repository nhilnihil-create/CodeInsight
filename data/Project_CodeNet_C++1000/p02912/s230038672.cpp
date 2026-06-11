#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    multiset<int,greater<int>> st;
    for (int i=0;i<n;i++)
    {
        int ele;
        scanf("%d",&ele);
        st.insert(ele);
    }
    for (int i=0;i<m;i++)
    {
        int val=*(st.begin());
        st.erase(st.begin());
        st.insert(val/2);
    }
    ll sum1=0LL;
    for (int x: st)
    sum1=sum1+1LL*x;
    printf("%lld\n",sum1);
    return 0;
}