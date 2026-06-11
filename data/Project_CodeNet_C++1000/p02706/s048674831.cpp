    #include <bits/stdc++.h>
    using namespace std;

    #define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define mod 1000000007
    #define qmod 998244353
    #define M 10000001
    #define endl "\n"
    #define all(a) (a).begin(),(a).end()
    #define rep(i,a,b) for(int i=a;i<b;++i)
    #define repr(i,a,b) for(int i=a;i>=b;--i)
    #define F first
    #define S second
    #define pb push_back
    #define mp make_pair

    typedef long long ll;
    typedef pair<int,int> pii;
    typedef vector<int> vi;
    typedef vector<string> vs;  
    typedef vector<pii> vii;
    typedef vector<vi> vvi;

    const double PI=acos(-1.0);

    int main(){ 
                            
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin); 
    // freopen("output.txt","w",stdout);   
    // #endif 

        fast;   
        int t=1;
        // cin>>t; 
        while(t--){
            int n,m;
            cin>>n>>m;
            int s=0;
            rep(i,0,m){
                int x;
                cin>>x;
                s+=x;
            }
            if(s>n) cout<<-1;
            else cout<<n-s;
        }  
        return 0;       
    }       


    // First, solve the problem. Then, write the code. 
    