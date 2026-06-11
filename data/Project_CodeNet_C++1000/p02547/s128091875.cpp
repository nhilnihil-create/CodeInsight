/*----------------------------------------------------*
* लेखक --> अमित सिंह
* संस्थान --> राष्ट्रीय प्रौद्योगिकी संस्थान, कुरुक्षेत्र
*-----------------------------------------------------*/
   #include <bits/stdc++.h>
   using namespace std;
   #define ll long long
   #define w(t) int t; cin>>t; while(t--)
   #define fo(i,n) for(int i=0;i<n;i++)
   #define endl "\n" 
   #define MOD 1000000007
   void Tez(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
   }
   int main(){
      Tez();
      int n;
      cin>>n;
      vector<pair<int,int>>v;
      for(int i=0;i<n;i++){
         int x,y;
         cin>>x>>y;
         v.push_back({x,y});
      }
      string ans="No";
      for(int i=2;i<n;i++){
         if(v[i].first==v[i].second && v[i-1].first==v[i-1].second && v[i-2].first==v[i-2].second){
            ans="Yes";
            break;
         }
      }
      cout<<ans;
      return 0;
   }

