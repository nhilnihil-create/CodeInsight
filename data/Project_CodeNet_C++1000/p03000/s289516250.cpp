#include<bits/stdc++.h>
using namespace std;

int main(){
  int N , X ;
  cin >> N >> X;
  vector<int> L(N);
  for(int i = 0; i < N; i++) cin >> L[i]; 
  int ans = 0;
  vector<int> XL(N + 1);
  for(int i = 1; i < N + 1; i++) XL[i] = XL[i-1] + L[i-1];
  for(int i = 0; i < N + 1; i++)
    if(XL[i] <= X) ans++;
  cout << ans << endl;
}