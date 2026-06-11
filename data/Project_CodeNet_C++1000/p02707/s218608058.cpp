#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N;
  cin >> N;
  vector<int> a(N + 1,0);
  froop1(0,N -1){
    int b;
    cin >> b;
    a.at(b)++;
  }
  froop1(1,N + 1){
    cout << a.at(i) << endl;
  }
  
return 0;
}