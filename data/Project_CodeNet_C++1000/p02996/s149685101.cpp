#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,count = 0,a,b;
  cin >> N;
  vector<pair<long long,long long>> c(N);
  froop1(0,N){
	cin >> c.at(i).second >> c.at(i).first;
  }
 sort(c.begin(),c.end());
    froop1(0,N){
      count += c.at(i).second;
      if(count > c.at(i).first){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
return 0;
}