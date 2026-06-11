


    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define FAST ios_base::sync_with_stdio(false);cin.tie(0);
    const double EPS = 1e-9;
    const double PI = acos(-1);
    const int knightDir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
    //const int dx[]={0,0,0,1,1,1,-1,-1,-1};
    //const int dy[]={-1,0,1,-1,0,1,-1,0,1};
    const int dx[] = {0 , 1 , 0 , -1};
    const int dy[] = {1 , 0 , -1 , 0};
    const int MAX  = 1e7 + 5;
    const ll MOD = 1000000000 + 7;

    ll f[MAX];
    void sieve(int n)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = i ; j <= n ; j += i)
            {
                f[j]++;
            }
        }
    }
    int main()
    {
        FAST
        int t;
        t = 1;
        
       
        while(t--)
        {
           int n;
           cin >> n;
           
           sieve(n);
           
           ll sum = 0;
           for(int i = 1 ; i <= n ; i++)
           {
               sum += i * f[i];
           }
           
           cout << sum << endl;
        }
    }

