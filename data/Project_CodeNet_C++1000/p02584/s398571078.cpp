    #include<bits/stdc++.h>

    #define ll long long int
    using namespace std;
    int main()
    {
        ll x,k,d;
        cin>>x>>k>>d;
        x = abs(x);
        ll opt = x/d;
        ll mod = x%d;
        if(opt < k) {
            x = mod;
            k -= opt;
            if(k & 1)
                x = d - x;
        }
        else 
            x -= d*k;
        cout<<x<<endl;
        return 0;

    }
