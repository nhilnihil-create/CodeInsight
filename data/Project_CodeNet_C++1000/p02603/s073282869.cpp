#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define endl        "\n"
#define inf         10000000002
#define pb          push_back
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define MAX         100
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define bye         return 0

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      //freopen("inputNew.txt", "r", stdin);

      ll n;
      cin>>n;
      ll arr[n];
      for(int i=0; i<n; i++){
            cin>>arr[i];
      }
      vector<ll>V[2];
      ll mn,mx;
      mx=arr[n-1];

      for(int i=n-2; i>=0; i--){
            if(arr[i]>=mx) mx=arr[i];
            else{
                  mn=arr[i];
                  ll temp=0;
                  while(i>0){
                        if(arr[i-1]<=mn){mn=arr[i-1]; i--;}
                        else{temp=arr[i-1];break;}
                  }
                  //cout<<mn<<"  "<<mx<<endl;
                  V[0].pb(mn);
                  V[1].pb(mx);
                  mx=temp;
            }

      }
      ll sz=V[0].size();
      reverse(V[0].begin(),V[0].end());
      reverse(V[1].begin(),V[1].end());

      ll money=1000;
      for(int i=0; i<sz; i++){
            ll s=(money/V[0][i]);
            money= (money%V[0][i]);

            money+= (s*V[1][i]);
      }
      cout<<money<<endl;


      bye;
}
