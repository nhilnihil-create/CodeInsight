#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define pb push_back
#define all(v) (v).begin(), (v).end()

int main(){
  int N;cin>>N;
  vi d(N);
  for(int i=0; i<N; i++)cin>>d[i];

  sort(all(d));

  int L = d[N/2-1];
  int R = d[N/2];

  cout<<R-L<<endl;
}