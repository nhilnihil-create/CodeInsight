    #include <bits/stdc++.h>
    using namespace std;
    #define   nl   <<'\n'
    #define   pi   acos(-1.0);
    #define   ll   long long
    #define   pb   push_back
    #define   eb   emplace_back
    #define   tc   int t; cin>>t; while(t--)
    #define   fio  ios_base::sync_with_stdio(0); cin.tie(0)

    ll a[2001];

    int main()
    {
        fio;
        int n;
        cin>>n;
        a[1]=a[2]=0,a[3]=a[4]=a[5]=1;
        if(n<6)
        {
            cout<<a[n] nl;
            return 0;
        }
        for(int i=6; i<=n; i++)
        {
            a[i]=a[i-1]+a[i-3];
            a[i]%=1000000007;
        }
        cout<<a[n] nl;
    }  