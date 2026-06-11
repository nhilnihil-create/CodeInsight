#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n;
cin >> n;
vector<int> a(n);
vector<int> b(n);
vector<int> c(n-1);
rep(i,n) cin >> a.at(i);
rep(i,n) cin >> b.at(i);
rep(i,n-1) cin >> c.at(i);

int sum = 0;
for(int i: b){
sum += i;
}

for(int i = 0; i < n-1 ;i++){
  if(a.at(i) == a.at(i+1) - 1){
    sum += c.at(a.at(i)-1);
  }
}
cout << sum << endl;
}
  
