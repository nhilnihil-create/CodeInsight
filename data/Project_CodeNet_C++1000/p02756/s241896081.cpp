#include<bits/stdc++.h>
using namespace std;

#define IOS             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define watch(x);       cout << "\n" <<  #x << " is: " << x << "\n";
#define ll              long long int
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define pb              push_back
#define nl              cout<<"\n"
#define gcd(a,b)        __gcd(a,b)
#define sq(a)           (a)*(a)
#define loop(i,a,b)     for (ll i = a; i <= b; i++)
#define rloop(i,a,b)    for (int i = a; i >= b; i--)
#define sz(a)           a.size()
#define mod             1000000007
#define PI              2*acos(0.0)

int main()
{
    IOS
    int T=1;
    //cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        deque<char>q;
        loop(i,0,sz(s)-1) q.pb(s[i]);
        int q1;
        cin>>q1;
        int flag=0;
        while(q1--)
        {
            int t;
            cin>>t;
            if(t==1) flag^=1;
            else
            {
                int f;
                char c;
                cin>>f>>c;
                if(f==1)
                {
                    if(flag)
                    q.pb(c);
                    else q.push_front(c);
                }
                else
                {
                    if(!flag)
                    q.pb(c);
                    else q.push_front(c);
                }
            }
        }
        if(!flag)
        for(auto p:q) cout<<p;
        else{
            reverse(all(q));
            for(auto p:q) cout<<p;
        }

    }
    return 0;
}
