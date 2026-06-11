//vinay
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;
#define flash ios_base::sync_with_stdio(false);cin.tie(0);
// C++ program to print all 
// permutations with duplicates allowed 
typedef pair<int, int > pii;
const int INF = 1e9+5;

int main(){
  int n;
  cin >> n;
  ll a[n];
  for(ll i = 0; i < n; i++){
      cin >> a[i];
  }
  ll sum = 0, mx = 0;
  for(ll i = 1; i < n; i++){
       
       if(a[i] < a[i-1]){
           sum += a[i-1]-a[i];
           a[i] = a[i-1];
       }
    }
    cout << sum << endl;
     

}