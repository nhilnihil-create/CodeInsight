#include <bits/stdc++.h>
#define P pair<long long, long long>

using namespace std;

int main(){
  long long n, d, a;
  P p[200009];
  cin >> n >> d >> a;
  for(int i=0;i<n;i++){
    long long x, h;
    cin >> x >> h;
    p[i] = P(x, h);
  }
  sort(p, p+n);
  priority_queue<P, vector<P>, greater<P> > q;
  long long total=0;
  long long cnt=0;
  for(int i=0;i<n;i++){
    while(!q.empty()&&q.top().first<p[i].first){
      total -= q.top().second;q.pop();
    }
    if(total<p[i].second){
      long long add = (p[i].second-total-1)/a + 1;
      cnt += add;
      total += add*a;
      q.push(P(p[i].first+2*d, add*a));
    }
  }
  cout << cnt << endl;
}
