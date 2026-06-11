#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	string s;
  int N;
  cin >> N;
  map<string,int> a;
  froop1(0,N){
    cin >> s;
    if(!a.count(s)){
      a[s] = 1;
    }
  }
  int count = 0;
  for(pair<string,int> p : a){
    count++;
  }
  cout << count << endl;
  
}