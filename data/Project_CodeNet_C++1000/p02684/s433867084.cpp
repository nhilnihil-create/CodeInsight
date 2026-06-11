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
//   typedef string str;
//   typedef unsigned long long ull;
  ll INF = INT_MAX;
  ll mod = 1000000007;
  lld PI = 3.141592653;

// const int N = 2e5 + 5;

// int a[N];
// int n,k;
  


  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     
     int n;
     ll k;
     cin>>n;
     cin>>k;
     vector<int> a(n+1);
     for (int i = 1;i<=n;i++) cin>>a[i];
      map<int, int> been_here;
    int step = 1;
  int now = 1;
  now = a[now];
  been_here[1] = step;
  step++;

  while (!been_here[now]){
    been_here[now] = step;
    step++;
    now = a[now];
  }
  // for (int i = 1;i<=n;i++) cout<<been_here[i]<<" ";
  //   cout<<endl;
  ll before = been_here[now]-1;
  ll cycle = step - been_here[now];
  // cout<<cycle<<endl;
  if (k<=before+cycle){
    now = 1;
    while(k--){
      now = a[now];
    }
    cout<<now<<"\n";
    return 0;
  }
  int start = now;
  k-=before;
  // cout<<start<<endl;
  k%=cycle;
  while (k--){
    start = a[start];
  }
  cout<<start<<"\n";
   
}
  