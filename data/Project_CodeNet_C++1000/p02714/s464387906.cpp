#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

// void sort3(int *x,int *y, int *z){
//   int index;
//   if (*y > *z){
//     index = *y;
//     *y = *z;
//     *z = index;
//   }
//   if (*x > *y){
//     index = *x;
//     *x = *y;
//     *y = index;
//   }
//   if (*y > *z){
//     index = *y;
//     *y = *z;
//     *z = index;
//   }
// }
// 
// int main(){
//   int n;
//   string s;
//   cin >> n >> s;
//   //int ans = 0;
//   // REP(i,0,n-2)REP(j,i+1,n-1)REP(k,j+1,n){
//   //   if (s.at(i) != s.at(j) && s.at(i) != s.at(k)
//   //    && s.at(j) != s.at(k) && j-i != k-j){
//   //     ans++;
//   //   }
//   // }
//   vector<pair<char, int>> vec(n);
//   rep(i,(int)n){
//     vec.at(i).first = s.at(i);
//     vec.at(i).second = i;
//   }
//   sort(vec.begin(), vec.end());
//   int ei, sj, ej, sk;
//   rep(i,n-1){
//     //cout << vec.at(i).first << " " << vec.at(i).second << endl;
//     if (vec.at(i).first == 'B' && vec.at(i+1).first == 'G'){
//       ei = i;
//       sj = i + 1;
//     }
//     if (vec.at(i).first == 'G' && vec.at(i+1).first == 'R'){
//       ej = i;
//       sk = i + 1;
//     }
//   }
//   //printf("%d %d %d %d\n", ei, sj, ej, sk);
//   int ans = 0;
// 
//   for (int i=0; i<=ei; i++)for (int j=sj; j<=ej; j++)for (int k=sk; k<n; k++){
//     int x, y, z;
//     x = vec.at(i).second;
//     y = vec.at(j).second;
//     z = vec.at(k).second;
//     //printf("%d %d %d\n", x, y, z);
//     sort3(&x, &y, &z);
//     //printf("%d %d %d\n\n", x, y, z);
//     if (y - x != z - y){
//       ans++;
//     }
//   }
//   cout << ans << endl;
//   return 0;
// }

int main(){
  int n;
  string s;
  cin >> n >> s;
  vi vec(n);
  rep(i,n) vec.at(i) = (int)s.at(i) % 3;
  vi cnt(3);
  rep(i,n) cnt.at(vec.at(i))++;
  ll ans = 1;
  rep(i,3) ans *= cnt.at(i);
  rep(j,n)rep(i,j){
    int k = j + (j - i);
    if (k < n){
      if (s.at(i) == s.at(j)) continue;
      if (s.at(j) == s.at(k)) continue;
      if (s.at(i) == s.at(k)) continue;
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
