//バケット法で解決
#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n , k , q , a ;
  cin >> n >> k >> q ;
  vector<long long> baketu(210000);
  for(int i=0;i<q;i++){
    cin >> a;
    baketu[a-1]++;
  }
  for(int i=0;i<n;i++){
    if(k+baketu[i]-q>0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
  
