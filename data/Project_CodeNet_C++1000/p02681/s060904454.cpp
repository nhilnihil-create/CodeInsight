#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
   string s;
   cin >> s;
   int n = s.size();
   string t;
   cin >> t;
   for(int i=0;i<n;i++){
       if(s.at(i) != t.at(i)){
           cout << "No" << endl;
           return 0;
       }
   }
   cout << "Yes" << endl;
   
}
       
