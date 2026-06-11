        #include <bits/stdc++.h>
        #define ll  long long int
        #define fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
        #define mod 1000000007
        using namespace std;
ll gcd(ll a, ll b){
    if(b==0)
        return a;


        return gcd(b, a%b);

}
ll arr[1000000+1], fact[1000000+1];
bool prime[1000000+1];

        int main()
            {fast;
            ll t =1;
            //cin>>t;

        while(t--){
            ll n;
            cin>>n;

            
            ll ma=0;
            for (int i=0; i<n;i++){
            cin>>arr[i];
            ma=max(arr[i],ma);
            }

       
            memset(prime,false,sizeof(prime));

     
          
            for(int i=0; i<=ma; i++)
                fact[i]=i;
            
            for(int i=2; i<=ma; i++){
                if(fact[i]==i)
                    for(ll j=2*i; j<=ma; j+=i){
                        if(fact[j]==j)
                        fact[j]=i;
                    }
                        
            }
            
    ll p=0;
            for (int i=0; i<n;i++){
             
                ll a=arr[i];
                while(a>1){
                    ll h=fact[a];
                    while(fact[a]==h)
                    a/=fact[a];

                    if(prime[h]==true)
                     {p=1;
                     break;
                     }
                    prime[h]=true;
                }
            }
            if(p==0)
            {cout<<"pairwise coprime";
            return 0;}

            p=0;
            ll a = gcd(arr[0], arr[1]);

           for(int i=0; i<n-1;i++)
            a = gcd(arr[i+1],a);

            if(a==1)
            cout<<"setwise coprime";
            else
            cout<<"not coprime";
            

        }
                return 0;
        }