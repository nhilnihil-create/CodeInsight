    #include<bits/stdc++.h>
    #include<algorithm>
    #include<cmath>
    #include<climits>
    using namespace std;
    typedef long long int lli;
    typedef vector<int> vi;
    typedef vector<long long int> vlli;
    typedef pair<int,int> pii;
    typedef pair<long long int,long long int> plli;
    typedef vector< vi > vvi ;
    typedef vector< vlli > vvlli  ;
    #define fi(i,a,b) for(int i=a;i<=b;i++)
    #define flli(i,a,b) for(long long int i=a;i<=b;i++)
    #define bi(i,a,b) for(int i=a;i>=b;i--)
    #define blli(i,a,b) for(long long int i=a;i>=b;i--)
    #define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define all(x) x.begin(),x.end()
    #define sz(x) x.size()
    #define pi 2*acos(0.0)
    #define pb push_back
    #define tr(v,it) for(decltype(v.begin()) it=v.begin();it!=v.end();it++)
    #define present(v,num) (v.find(num)!=v.end())
    #define cpresent(v,num) (find(v.begin(),v.end(),num)!=v.end())
    #define pq priority_queue
    #define mp make_pair
    const int inf=INT_MAX;
    const lli INF =LLONG_MAX;
    const lli mod = 1e9+7;
    int main() {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        fast;
        lli n;cin>>n;
        vlli ans(n+1,0);
        flli(i,1,10000)
        {
            if(i*i>n)break;
            flli(j,1,10000)
            {
                if(i*i+j*j+i*j>n)break;
                flli(k,1,10000)
                {
                    lli var=i*i+j*j+k*k+i*j+j*k+k*i;
                    if(var>n)break;
                    if(var<=n)ans[var]++;
                }
            }
        }
        flli(i,1,n)cout<<ans[i]<<endl;
        cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
        return 0;
    }