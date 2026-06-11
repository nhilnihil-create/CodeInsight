#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define INF 2147483647
using namespace std;
using Graph=vector<vector<int>>;

int main(){
  int n; cin>>n; int a[n],b[n];
  rep(i,n){
    cin>>a[i]>>b[i];
  }
  sort(a,a+n);
  sort(b,b+n);
  if(n%2==1){
    cout<<b[(n-1)/2]-a[(n-1)/2]+1;
  }else{
    cout<<b[n/2]+b[n/2-1]-a[n/2]-a[n/2-1]+1;
  }
}
