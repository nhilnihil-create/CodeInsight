#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
   ll N;
   int ai, i;
   cin >> N;
   vector<ll> count(N, 0);
   for(i=0;i<N-1;i++){
       cin >> ai;
       count.at(ai-1) += 1;
   }
   for(i=0;i<N;i++){
       cout << count.at(i) << endl;
   }

    return 0;
}
