#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
int main(){
	int x[5],m;
  rep(i, 5){
    cin >> x[i];
    if (x[i]==0) m=i+1;
  }
  cout << m << endl;
}
