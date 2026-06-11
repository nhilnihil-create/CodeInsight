#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      int k=0;
      while((i>>k&1)==(j>>k&1)) k++;
      cout << k+1 <<  " ";
    }
    cout << endl;
  }
}
