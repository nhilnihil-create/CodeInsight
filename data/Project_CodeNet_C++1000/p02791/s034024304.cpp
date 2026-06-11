#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
  int n, count = 1, a, min;
  cin >> n >> min;
  Srep(i,1,n){
    cin >> a;
    if(min > a){
      min = a;
      count++;
    }
  }
  cout << count << endl;
}
