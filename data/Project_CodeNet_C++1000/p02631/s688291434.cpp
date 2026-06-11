// In god we trust
 
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <signal.h>
#include <thread>
 
#define pb push_back
#define fi first
#define se second
#define Vi vector<int>
#define Vb vector<bool>
#define Pi pair<int, int>
#define MP make_pair
#define MT make_tuple
#define Q queue
#define Qi Q<int>
#define INF 1000000000 
#define LINF 1000000000000000000
#define int long long
using namespace std;
using namespace std::chrono;

int c[100010];

signed main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int n;
  cin >> n;
  int a[n];
  int X = 0;

  for (int i = 0; i < n; i++){
    cin >> a[i];
    X ^= a[i];
  }
  
  for (int i = 0; i < n; i++)
    cout << (X^a[i]) << " ";
  cout << endl;
  

 

  
}
