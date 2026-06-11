
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
   int n;
   string s;
   cin >> n >> s;
   int count=0;
   for(int i=0; i<n-2; i++){
       if(s.at(i)=='A' && s.at(i+1)=='B' && s.at(i+2)=='C'){
           count ++;
       }
   }

    cout << count << endl;
}