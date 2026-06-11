#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  int n,k;
  cin >> n >> k;
  //int a[n];
  vector<int> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  //int b[n] ={0};
  //vector<int> b(n+1); //b[n+1]にしとくと便利。aと比較する時は末尾消す
  for(int x=0; x<k; x++){
    vector<int> b(n+1); //前のxの時の引きずらないように
    for(int i=0; i<n; i++){
      int l=max(0,i-a[i]);
      int r=min(i+a[i]+1,n);
      b[l]++;
      b[r]--;
    }
    for(int i=0; i<n; i++)
      b[i+1]+=b[i];
    b.pop_back();
    if(a==b)
      break;
    a=b; //vectorで配列宣言すると出来る
  }
  for(int i=0; i<n; i++) //a:1~nから0~n-1にしたのに添字変え忘れた
    cout << a[i] << '\t';
}