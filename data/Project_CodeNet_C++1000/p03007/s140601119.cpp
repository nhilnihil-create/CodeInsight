#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;cin>>n;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  sort(a.begin(), a.end());

//cout<<a[0]<<' '<<a[n-1]<<endl;

  ll result = a[n-1], tmp_result = a[0];
  vector<ll> op;

  if(a[0]>0){
    result = a[0];
    rep(i, n-1){
      if(result-a[i+1] > a[i+1]-result)swap(result, a[i+1]);
      if(i==n-2)swap(result, a[i+1]);
      op.push_back(result);
      op.push_back(a[i+1]);
      result-=a[i+1];
    }
  }else if(a[n-1]<0){
    if(a[n-1]<0)sort(a.rbegin(), a.rend());
    result = a[0];
    rep(i, n-1){
      if(result-a[i+1] < a[i+1]-result)swap(result, a[i+1]);
      op.push_back(result);
      op.push_back(a[i+1]);
      result-=a[i+1];
    }
  }else{
    result = a[n-1];//plus or zero
    tmp_result = a[0];//minus or zero
    rep(i,n-2){
      if(a[i+1]>0){
        op.push_back(tmp_result);
        op.push_back(a[i+1]);
        tmp_result -= a[i+1];
      }else{
        op.push_back(result);
        op.push_back(a[i+1]);
        result-=a[i+1];
      }
    }
    op.push_back(result);
    op.push_back(tmp_result);
    result -= tmp_result;
  }

  cout<<result<<endl;
  rep(i,n-1)cout<<op[i*2]<<' '<<op[i*2+1]<<endl;

  return 0;
}