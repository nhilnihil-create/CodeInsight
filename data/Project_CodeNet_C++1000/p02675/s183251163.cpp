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
   if(n %10 == 3)cout << "bon" << endl;
   else if ( n %10 == 0 || n %10 == 1 || n %10 == 6 || n %10 == 8)cout << "pon" << endl;
   else cout << "hon" << endl;
}
       
