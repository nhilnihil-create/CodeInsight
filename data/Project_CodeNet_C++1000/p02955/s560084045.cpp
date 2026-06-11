#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n,k;
  cin>>n>>k;
  int min=10000000,sum=0;
  vector<int> A;
  rep(i,n){
    int a;
    cin>>a;
    if(min>a) min=a;
    sum+=a;
    A.push_back(a);
  }
  
  rep(i,sum){
    int num=sum-i;
    if(sum%num!=0) continue;
    priority_queue<int,vector<int>,less<int>> amari;
    int numsum=0;
    rep(j,n){
      amari.push(A[j]%num);
      numsum+=A[j]%num;
    }
    rep(j,numsum/num) amari.pop();
    int count=0;
    while(!amari.empty()){
      count+=amari.top();
      amari.pop();
    }
    if(count<=k){
      cout<<num<<endl;
      break;
    }
  } 
}