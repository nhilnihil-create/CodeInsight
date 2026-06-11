#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
typedef long long ll;

int main(){
   long long N,K;
   cin >> N >> K;
   long long A[N];
   long long S = 0;
   for (int i = 0; i < N; i++)
   {
      cin >> A[i];
      S+=A[i];
   }
   vector<int> cand;
   for(int i = 1; i*i <= S; i++){
      if(S%i==0){
         cand.emplace_back(i);
         cand.emplace_back(S/i);
      }
   }
   sort(cand.begin(),cand.end());
   reverse(cand.begin(),cand.end());
   for(int c: cand){
      vector<pair<int,int>> ps;
      ll pos =0;
      ll neg =0;
      for(int i=0;i<N;i++){
         int p = A[i]%c;
         ps.push_back(make_pair(p,c-p));
         pos+=c-p;
      }
      sort(ps.begin(),ps.end());
      long long score = max(0LL,pos);
      for(pair<int,int> p: ps){
         neg += p.first;
         pos -= p.second;
         score = min(score, max(neg,pos));
      }
      //cout << c << ": " << score << endl;
      if(score<=K){
         cout << c << endl;;
         return 0;
      }
   }

   cout << 1 << endl;   
   return 0;
}
