#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc = 1; 
    //cin >> tc;
    while(tc--){
        int n,p; cin >> n;
        set<int> ans;
        for(int i = 2; i*i <= n; i++)
        {   
            if(n % i == 0)
            {
                p = n;
                while(p%i == 0)
                    p /= i;
                if(p%i == 1)
                    ans.insert(i);
                p = n;
                while(p%(n/i) == 0)
                    p /= (n/i);
                if(p%(n/i) == 1)
                    ans.insert(n/i);
            }
        }
        ans.insert(n);
        n--;
        for(int i = 2; i*i <= n; i++)
            if(n%i == 0)
            {
                ans.insert(i);
                ans.insert(n/i);
            }
        if(n > 1)
            ans.insert(n);
        cout << ans.size();
    }    
}