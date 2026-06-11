#define radhey krishna
#include<bits/stdc++.h>   
using namespace std;
#define ll long long
#define endl "\n"
 const unsigned int M = 1000000007;
//std::set<int> neg ;
 const int MN = 100;
 string v[MN];
  //vector<pair<ll ,ll >>p;
  int solve (string x ,string y){
    int cnt = 0;       
   for(int i = 0; i <x.size() ; i++){
    if(x[i] != y[i])
      cnt++;
   }
   return cnt;
  }   
int main(){  
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);  
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
       ios_base::sync_with_stdio(false);  
 string s = "ACL";
 int k;
 cin>>k;
 for(int i = 0; i < k ;i++){   
  cout<<s;
 }
}