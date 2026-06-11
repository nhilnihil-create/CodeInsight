#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
   int n;   cin >> n;
   string s;    cin >> s;
   int l = s.size();
   
   if(l>n){
       for(int i=0;i<n;i++){
       cout << s.at(i);
   }
   cout << "..." << endl;
}
else cout << s << endl;
}
       
