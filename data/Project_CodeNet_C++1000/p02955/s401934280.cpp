#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, k; cin >> n >> k;
  vector<int> a(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  priority_queue<long long> que;
  for(int i = 1; i < sqrt(sum) + 1; i++){
    if(sum % i == 0){
      que.push(i); que.push(sum / i);
    }
  }
  for(long long l = 1; l <= sum; l++){
    long long s = que.top();
    que.pop();
    long long pl = 0, mi = 0;
    priority_queue<long long> qm, qp;
    for(int i = 0; i < n; i++){
      long long ama = a.at(i) % s;
      if(ama > 0){
        if(ama <= s / 2){
          mi += ama;
          qm.push(ama);
        }else{
          pl += s - ama;
          qp.push(s - ama);
        }
      }else{
        if(-(ama) <= s / 2){
          pl += -(ama);
          qp.push(-(ama));
        }else{
          mi += s + ama;
          qm.push(s + ama);
        }
      }
    }
    long long hi, za;
    if(pl <= mi){
      hi = pl; za = mi - pl;
      long long no = 0;
      for(int j = 0; j < za / s; j++){
        no += qm.top();
        qm.pop();
      }
      hi += za;
      hi -= no;
    }else{
      hi = mi; za = pl - mi;
      long long no = 0;
      for(int j = 0; j < za / s; j++){
        no += qp.top();
        qp.pop();
      }
      hi += za;
      hi -= no;
    }
    if(k - hi >= 0){
      cout << s;
      return 0;
    }
  }
}