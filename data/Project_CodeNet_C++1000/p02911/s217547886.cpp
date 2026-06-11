










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

   

signed main()  {    

        fastio();         

         int t=1;           

          // cin>>t;                

           while(t--)                  

              {                        

                      int m,k,n;

                      cin>>m>>k>>n;

                      int a[n];

                      int ma[m+2]={};

                      for(int i=0;i<n;i++){

                        cin>>a[i];

                        ma[a[i]]++;

                      }

                      for(int i=1;i<=m;i++){

                      	int p=k-(n-ma[i]);

                      	if(p<=0)

                      	cout<<"No\n";

                      	else

                      	cout<<"Yes\n";

                      }

               }  

                  

    }    