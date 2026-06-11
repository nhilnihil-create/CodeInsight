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
  // lld PI = 3.141592653;

// const int N = 2e5 + 5;

// int a[N];
// int n,k;

set<ll> all;

void go(ll num, int len){
  
  if (len==0){

    all.insert(num);
    return;
  }
  if (num%10==0){
    go(num*10, len-1);
    go(num*10+1, len-1);
  }else if (num%10==9){
    go(num*10+9, len-1);
    go(num*10+8, len-1);
  }else{
    go(num*10 + num%10, len-1);
    go(num*10 + num%10-1, len-1);
    go(num*10 + num%10+1, len-1);
  }
}

void make(int len){
  for (int i = 1; i<=9;i++){
    // cout<<i<<" "<<len<<endl;
    go(i, len-1);
  }
}


  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      
      int k;
      cin>>k;
      int len = 1;
      while(all.size()<k){
        make(len);
        len++;
      }

      
      set<ll>::iterator it;
      it = all.begin();
      // while (it!=all.end()){
      //   cout<<*it<<endl;
      //   it++;
      // }

      while (k!=1){
        k--;
        // cout<<*it<<endl;
        it++;
      }
      cout<<*it<<"\n";
     

      
}
  