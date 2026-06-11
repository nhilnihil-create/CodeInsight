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

           // cin>>t;

                while(t--)

                    {

                         int n,c=0,m=0;

                         cin>>n;

                         int a[n];

                         for(int i=0;i<n;i++)

                             cin>>a[i];           

                          for(int i=0;i<n-1;i++){

                                  if(a[i]>=a[i+1])  

                                  c++;

                                  else

                                  {

                                     m=max(c,m);

                                     c=0;

                                  }

                                  }

                                  m=max(c,m);

                                  cout<<m;

    }

    }

    