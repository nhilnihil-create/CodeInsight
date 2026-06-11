    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;

    int main()
    {
        int k,c=0;
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=k;j++)
            {
                for(int a=1;a<=k;a++)
                {
                    c+=__gcd(i,__gcd(j,a));
                }
            }
        }
        cout<<c;

          return 0;
    }
