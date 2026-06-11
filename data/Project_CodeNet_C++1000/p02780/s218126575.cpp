#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pii;

int32_t main()
{
 int k , n ; 
 cin >> n >> k;
 int p[n + 1] ;
 for(int i = 1 ; i <= n ; i++)
  cin >> p[i] ;

 int cm[n + 1] ;
 for(int  i = 1; i <= n ; i++)
  cm[i] = cm[i-1] + p[i] ;

 // double ans = 0.0;
 int ans = 0 ;
 for(int i = 0 ; i + k <= n  ; i++){
  int st = i , en = i + k  ;
  int val = cm[en] - cm[st] ;
  ans = max(ans , val ) ;
  // cout << st <<" "<<en <<" ";
  // cout << val <<"\n" ;
 }

 double a = (double)(k / 2.0) + (double) (ans / 2.0) ;

 printf("%.14f\n", a );
 return 0;
}        