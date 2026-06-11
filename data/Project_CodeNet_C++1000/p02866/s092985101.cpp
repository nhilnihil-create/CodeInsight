    #include <bits/stdc++.h>
    using namespace std;
    #define forn(i,n) for(int i = 0 ; i < n ;i++)
    #define ll long long int
    #define ld long double
    int main()
    { 
        ll mod = 998244353;
    	int n;
    	cin >> n;
    	int d[n];
    	forn(i,n)cin >> d[i];
    	if(d[0] != 0){cout<<0<<"\n";return 0;}
    	int a[n];
    	memset(a,0,sizeof(a));
    	forn(i,n)a[d[i]]++;
        if(a[0] > 1){cout<<0<<endl;return 0;}
    	bool f1;
    	f1 = false;
        forn(i,n){
    		if(a[i] == 0 && f1 == false)f1=true;
    		if(f1 == true && a[i] != 0){
    			cout<<0<<"\n";return 0;
    		}
    	}
    	long long int ans = 1;
    	for(int i = 2; i<n ;i++)
    	{
    		if(a[i-1] >= 2  && a[i]!=0)
            {
                for(int j = 1; j<= a[i]; j++)
    			ans = (ans*a[i-1])%mod;
            }
    	}
    	cout<<ans<<"\n";
    return 0;
    }