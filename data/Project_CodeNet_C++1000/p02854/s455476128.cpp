#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++) 
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b); 
#define chmax(a,b) if((a)<(b)) (a)=(b);
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a=a%b;}return max(a,b);
}
int dx[]={0,1,0,-1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e10+10;
struct Edge{int to,weight;};

/*----------------------------------------------*/
string s[50];


signed main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  int check=0;
  int left=0,right=n-1;
  while(left<right){
    if(check<=0){
      check+=a[left];
      left++;
    }else{
      check-=a[right];
      right--;
    } 
  }
  int ans=INF;
  chmin(ans,abs(check+a[left]));
  chmin(ans,abs(check-a[left]));
  cout<<ans<<endl;;
  
  return 0;
}