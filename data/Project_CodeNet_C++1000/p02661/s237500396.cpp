  #include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>

  using namespace std;
   

//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
  typedef long long ll;
  typedef long double lld;
  typedef string str;
  typedef unsigned long long ull;
  ll INF = INT_MAX;
  // ll mod = 998244353;
  lld PI = 3.141592653;

// const int N = 2e5 + 5;

// int a[N];
// int n,k;



// void solve(){

// string s;
// cin>>s;


// }
 


  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
      
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0;i<n;i++){int k; cin>> k; a[i] = k; cin>>k; b[i] = k;}
  sort(a.begin(), a.end());
sort(b.begin(), b.end());

if (n%2==1){
  int amed = a[n/2];
  int bmed = b[n/2];
  cout<< max(abs(bmed-amed)+1, 0) <<"\n";
}else{
  lld amed = (a[n/2]+(lld)a[n/2-1])/2;
  lld bmed = (b[n/2]+(lld)b[n/2-1])/2;
  cout<< max(int(abs(bmed-amed)*2+1), 0)<<"\n";
}
  
}
