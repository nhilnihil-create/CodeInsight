#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
  ll n; cin >> n;
  if(n%2==1){
    cout << (n-1)/2 << endl;
  }else{
    cout << (n-2)/2 << endl;
  }
}
