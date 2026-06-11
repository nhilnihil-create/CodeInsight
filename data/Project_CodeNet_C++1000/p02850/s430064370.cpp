#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N;
   cin >> N;
   vector<int> a(N - 1), b(N - 1);

   for(int i = 0; i < N - 1; i++) {
       cin >> a[i] >> b[i];
       a[i]--; b[i]--;
   }

   vector<int> G[N];
   vector<pair<int, int>> E_in;
   for(int i = 0; i < N - 1; i++) {
       G[a[i]].emplace_back(b[i]);
       G[b[i]].emplace_back(a[i]);
       E_in.emplace_back(make_pair(a[i], b[i]));
   }

   
   queue<int> q;
   q.push(0);

   int used[N] = {0};
   int parent[N] = {0};
   map<pair<int, int>, int> E_out;
   used[0] = 1;
   int color_max = 0;
   while(!q.empty()) {
       int state = q.front();
       q.pop();
       int color_num = 0;
       for(auto i : G[state]) {
        if(used[i] != 1) {
            used[i] = 1;
            color_num++;

            if(color_num == parent[state]) color_num++;
            E_out[make_pair(state, i)] = color_num;
            parent[i] = color_num;
            q.push(i);
        }

       }
       if(color_max < color_num) color_max = color_num;

   }

   cout << color_max << endl;
   for(auto a : E_in) {
       cout << E_out[a] << endl;
   }

    return 0;
}