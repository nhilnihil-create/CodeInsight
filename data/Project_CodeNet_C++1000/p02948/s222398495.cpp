#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const ll INFL = (1LL << 60);
 const int INFI = (1 << 30);

 int main() {
   int N, M; cin >> N >> M;
   vector<pii> AB(N);
   rep(i, 0, N) cin >> AB.at(i).first >> AB.at(i).second;

   sort(AB.begin(), AB.end());

   priority_queue<int> pq;
   int ans = 0, tmp = 0;

   rep(i, 1, M + 1) {
     rep(j, tmp, N) {  //i日後にもらえる仕事のBiをpush
       if (AB.at(j).first == i) pq.push(AB.at(j).second);
       else if (AB.at(j).first > i) {
         tmp = j;
         break;
       }
     }
     if (!pq.empty()) {
       ans += pq.top();
       pq.pop();
     }
   }

   cout << ans << endl;
 }
