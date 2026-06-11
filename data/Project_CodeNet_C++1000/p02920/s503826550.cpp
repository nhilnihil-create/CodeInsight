#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
const int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset<int>st;
    int n;
    cin >> n;
    f(1<<n) {
        int x;
        cin >> x;
        st.insert(x);
    }
    queue<int>q;
    q.push(*st.rbegin());
    st.erase(--st.end());
    //cout << "GG" << endl;
    while (q.size()) {
        int now = q.front();
        q.pop();
        if (st.size() && *st.begin() >= now) {
            cout << "No\n";
            exit(0);
        }
        if (!st.size()) continue;
        int x = *prev(st.lower_bound(now));
        //cout << x << endl;
        st.erase(st.find(x));
        q.push(now);
        q.push(x);
    }
    cout << "Yes\n";
}
