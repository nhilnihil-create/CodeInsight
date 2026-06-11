    #include <bits/stdc++.h>
    using namespace std;
    #define   nl   <<'\n'
    #define   pi   acos(-1.0);
    #define   ll   long long
    #define   pb   push_back
    #define   eb   emplace_back
    #define   tc   int t; cin>>t; while(t--)
    #define   fio  ios_base::sync_with_stdio(0); cin.tie(0)

    int main()
    {
        fio;
        int n;
        cin>>n;
        ll a=1,b=1,c=1;
        for(int i=0; i<n; i++)
        {
            a*=10;
            a%=1000000007;
            b*=9;
            b%=1000000007;
            c*=8;
            c%=1000000007;
        }
        //cout<<a nl<<b nl<<c nl;
        a=(((a-2*b+c)%1000000007)+1000000007)%1000000007;
        cout<<a nl;
    }  