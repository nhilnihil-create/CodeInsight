#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int main()
{
  int ans = 0;
  int n;
  vector<int> a,b,c;
  cin >> n;
  REP(i,0,n){
    int inter;
    cin >> inter;
    a.push_back(inter);
    c.push_back(i+1);
  }
  REP(i,0,n){
    int inter;
    cin >> inter;
    b.push_back(inter);
  }

  int cnt=0;
  do{
    int a_co=0, b_co=0;
    cnt++;
    REP(i,0,n){
      if(c[i] == a[i])a_co++;
      if(c[i] == b[i])b_co++;
    }
    if(a_co==n)ans+=cnt;
    if(b_co==n)ans-=cnt;
  }while(next_permutation(c.begin(),c.end()));

  cout << abs(ans) << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}