    #define    ll           long long
    #define    dn           double
    #define    mp           make_pair
    #define    pb           push_back
    #define    se           second
    #define    fi           first
    #define    mod          1000000007
    #define    sob(v)       v.begin(),v.end()
    #define    sobr(v)      v.rbegin(),v.rend()
    #define    fr(i,a,b)    for(int i=a;i<=b;++i)
    #define    frr(i,a,b)   for(int i=a;i>=b;--i)
    #define    pi           acos(-1.00)
    #define    check        cout<<"*"<<endl
    #define    ffix(x)      cout<<fixed<<setprecision(x)
    #define    fast         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

    #include<bits/stdc++.h>
    #include<string.h>
    using namespace std;


    typedef vector<int> vi;
    typedef map<int,int> mii;
    typedef pair<int,int> pii;
    typedef pair<int,vi> pp;

    int dr[8]= {0,0,-1,1,-1,-1,+1,+1};
    int dc[8]= {-1,1,0,0,-1,+1,-1,+1};

    const int N=2000000;

    int main()
    {
        int a,b,c,k;
        cin>>a>>b>>c>>k;
        if(a>=b)
        {
            while(k>0)
            {
                b*=2;
                k--;
                if(b>a)break;
            }
        }
        if(b>=c)
        {
            while(k>0)
            {
                c*=2;
                k--;
                if(c>b)break;
            }
        }
        if(c>b && b>a)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
