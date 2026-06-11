                                              // #include <ext/pb_ds/assoc_container.hpp> 
                                            // #include <ext/pb_ds/tree_policy.hpp> 
                                                #include <iostream>
                                                #include <iomanip>
                                                #include <sstream>
                                                #include <cstring>
                                                #include <vector>
                                                #include <deque>
                                                #include <queue>
                                                #include <set>
                                                #include <map>
                                                #include <valarray>
                                                #include <iterator>
                                                #include <functional>
                                                #include <limits>
                                                #include <algorithm>
                                                #include <numeric>
                                                #include <cmath>
                                                #include <cassert>
                                                #include <unordered_map>
                                                #include <unordered_set>
                                                #include <stack>
                                                using namespace std;
                                                #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
                                                 #define trace(x) cerr << #x << ": " << x << " " << endl;
                                             
                                                typedef int64_t ll;
                                             
                                                #define endl '\n'
                                               // #define int ll
                                                ll mod=1e9+7;
                                                ll mod1=1e9+6;
                                                
                                                ll power(ll a,ll b)
                                                {
                                                    if(b==0) return 1;
                                                    else if(b%2==0)
                                                        return power((((a%mod)*(a%mod))%mod),b/2)%mod;
                                                    else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
                                                }
                                               
                                               //using namespace __gnu_pbds;
                                               //#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
                                                //find_by_order(k)  returns iterator to kth element starting from 0;
                                                //order_of_key(k) returns count of elements strictly smaller than k;
                                                //erase,insert same as normal set
                                            int n,m;
                                            int a[2001];
                                            int b[2001];    
                                            
                                            int32_t main()
                                            {
                                                IOS
                                               
                                            
                                                cin>>n>>m;
                                                for(int i=1;i<=n;++i)
                                                    cin>>a[i];
                                                for(int j=1;j<=m;++j)
                                                    cin>>b[j];
                                                int dp[n+1][m+1];
                                                memset(dp,0,sizeof(dp));
                                                for(int i=1;i<=n;++i)
                                                {
                                                    for(int j=1;j<=m;++j)
                                                    {
                                                        if(a[i]==b[j])
                                                        {
                                                            dp[i][j]=dp[i-1][j]+dp[i][j-1]+1;
                                                            dp[i][j]%=mod;
                                                        }
                                                        else
                                                        {
                                                            dp[i][j]=((dp[i-1][j]+dp[i][j-1])%mod-dp[i-1][j-1]+mod)%mod;
                                                            dp[i][j]%=mod;
                                                        }
                                                    }
                                                }
                                                cout<<(dp[n][m]+1)%mod;

                                                                             
                                                                                                                                                                                                    
                                             }                                                           
