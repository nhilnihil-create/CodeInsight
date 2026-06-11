#include<bits/stdc++.h> 

#include<random> 

#define int long long 

#define pp pair<int,int> 

#define ss second 

#define ff first 

#define pb push_back 

#define mod 1000000007 

using namespace std; 

void fastio() 

{ 

    #ifndef ONLINE_JUDGE 

        freopen("INPUT.txt","r",stdin); 

            freopen("OUTPUT.txt","w",stdout); 

                #endif 

                    ios_base :: sync_with_stdio(false); 

                        cin.tie(NULL) ; 

                            cout.tie(NULL); 

                            }

signed main() 

{ 

    fastio(); 

        int t=1;

            //cin>>t;

                while(t--)

                    {

                       int n,s=0;

                       cin>>n;

                       n--;

                       int a[n],b[n],c[n-1];

                       for(int i=0;i<n;i++)

                       cin>>a[i];

                      

                      for(int i=0;i<n-1;i++){

                       if(a[i]>a[i+1])

                       s+=a[i+1];

                       else

                       s+=a[i];

                      }

                      s+=a[0]+a[n-1];

                      

                       cout<<s;

                       

    }

    }

    