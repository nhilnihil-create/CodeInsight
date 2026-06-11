        #include<bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        ll INF =1e9+7;
        typedef pair<ll,ll> ii;
        #define f(i,a,b) for(long long i = a;i < b;i++)
        #define rf(i,a,b) for(long long i=a;i>=b;i--)
        #define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        #define w(t) while(t--)
        #define c(n); cin>>n;
        #define p(n) cout<<n;
        #define pl(n) cout<<n<<endl;
        #define ps(n); cout<<n<<" ";
        int main(void){
            fastio;
            ll t1,t2,a1,a2,b1,b2;
            c(t1);
            c(t2);
            c(a1);
            c(a2);
            c(b1);
            c(b2);
            ll ans=0;
            if(t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2){
                pl("infinity");
                return 0;
            }
            if(max(a1,b1) == a1 && max(a2,b2) == a2){
                pl(0);
                return 0;
            }
            if(max(a1,b1) == b1 && max(a2,b2) == b2){
                pl(0);
                return 0;
            }
          	if(max(a1,b1) == a1 && t1 * a1 + t2 * a2 > t1 * b1 + t2 * b2){
              pl(0);
              return 0;
            }
          	if(max(a1,b1) == b1 && t1 * a1 + t2 * a2 < t1 * b1 + t2 * b2){
              pl(0);
              return 0;
            }
            ll t = 1;
            ll d = abs((t1 * a1 + t2 * a2) - (t1 * b1 + t2 * b2));
            ans = (t1 * abs(a1-b1))/d;
            if( (t1 * abs(a1-b1)) % d == 0){
                t = 0;
            }
            pl(2*ans+t)
        }