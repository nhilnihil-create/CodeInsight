#include<bits/stdc++.h>

#define debug(n) cerr << #n << ':' << n << endl;

using namespace std;

using  ll = long long;

template<class T,class U>
using umap = unordered_map<T,U>;

template<class T>
using uset = unordered_set<T>;

template<class T>
inline bool change_max(T&a, const T&b){
  if(b > a){
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool change_min(T&a, const T&b){
  if(a > b){
    a = b;
    return true;
  }
  return false;
}


int main(){
  #define int ll
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);

  priority_queue<pair<int, int>> pq;

  bitset<200000> bs = 0;
  int finished = 0;
  
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }

  for(int i = 0; i < n; ++i){
    cin >> b[i];
    pq.push({b[i], i});
    if(a[i] == b[i]){
      bs[i] = 1;
      finished++;
    }
    if(a[i] > b[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  int cnt = 0;
  while(!pq.empty()){
    if(finished == n){
      cout << cnt << endl;
      return 0;
    }
    while(!pq.empty() && bs[pq.top().second] == 1){
      pq.pop();
    }
    if(pq.empty()){
      cout << cnt << endl;
      return 0;
    }
    int val, pos;
    tie(val, pos) = pq.top();
    pq.pop();
    int r = pos + 1, l = pos - 1;
    if(l < 0) l += n;
    if(r >= n) r -= n;

    int mns = b[r] + b[l];
    int div = (b[pos] - a[pos]) / mns;
    if(div == 0){
      cout << -1 << endl;
      return 0;
    }
    cnt = (cnt + div);
    b[pos] -= div*mns;
    
    if(b[pos] < a[pos]){
      cout << -1 << endl;
      return 0;
    } else if(b[pos] == a[pos]){
      bs[pos] = 1;
      finished++;
    } else {
      pq.push({b[pos], pos});
    }
    
  }
  cout << cnt << endl;
  return 0;
}
