#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  map<long long,long long> mp;
  for(long long i=0;i<n;++i){
    cin >> a[i];
    mp[a[i]]++;
  }
  bool ans=false;
  if(mp.size()==3){
    vector<bitset<100>> bs;
    for(auto p : mp){
      if(p.second!=n/3){
        cout << "No" << endl;
        return 0;
      }
      bs.push_back(p.first);
    }
    if((bs[0]^bs[1])==bs[2]){
      cout << "Yes" << endl;
      return 0;
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  if(mp.size()==1){
    for(auto p : mp){
      if(n==p.second && p.first==0){
        ans=true;
      }
    }
  }

  if(mp.size()==2){
    vector<pair<long long,long long>> pp(2);
    long long k=0;
    for(auto p : mp){
      pp[k]=make_pair(p.first,p.second);
      k++;
    }
    sort(pp.begin(),pp.end());
    if(n%3==0 && pp[1].first==0){
      if(pp[1].second==n/3){
        ans=true;
      }
    }
    if(n%3==0 && pp[0].first==0){
      if(pp[0].second==n/3){
        ans=true;
      }
    }
  }

  if(ans==true){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
