#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;

#define rep(i,n) for(int i=0; i<(n); i++)


template <class dt>
class Solve_Path{
    public:
        //edges[from][to]
        vector<vector<dt>> edges;
        //edges[from][to][id] 多重辺
        vector<vector<vector<dt>>> edges_mul;
        // edges[from][num] = {to, cost}
        vector<vector<pair<int, dt>>> edges_light;
        dt inf;
        int n;
        Solve_Path(int _n, dt _inf){
            // 無限大のコストを割り当てる(実質通れない）
            n = _n;
            inf = _inf;
        }
        void enable_edges(){
            edges = vector<vector<dt>>(n, vector<dt>(n, inf));
        }
        void enable_edgesmul(){
            edges_mul = vector<vector<vector<dt>>>(n, vector<vector<dt>>(n, vector<dt>()));
        }
        void enable_edges_light(){
            edges_light = vector<vector<pair<int, dt>>>(n, vector<pair<int, dt>>());
        }
        void conv_multo2d(){
          enable_edges();
          int n = edges_mul.size();
          rep(i, n){
            rep(j, n){
                for (int id = 0; id < edges_mul[i][j].size(); id++){
                    edges[i][j] = min(edges[i][j], edges_mul[i][j][id]);
                }
            }
          } 
          vector<vector<vector<dt>>> edges_mul;
          vector<vector<vector<dt>>>().swap(edges_mul);    
        }
        void add_path(int from, int to, dt cost){
            edges[from][to] = cost;
            return;
        }
        void add_path(int from, int to){
            edges[from][to] = 1;
            return;
        }        
        void add_path_mul(int from, int to, dt cost){
            edges_mul[from][to].push_back(cost);
        }
        void add_path_mul_nonDir(int from, int to, dt cost){
            edges_mul[from][to].push_back(cost);
            edges_mul[to][from].push_back(cost);
            return;
        }
        void add_path_light(int from, int to, dt cost){
            edges_light[from].push_back({to, cost});
        }       
        
        vector<int> get_NumberOfEdges_nonvec(const vector<vector<vector<dt>>>& edge_list_mul3){
            vector<int> num_edge = vector<int>(n, 0);
            rep(i, n){
                rep(j, i){
                    for (int id = 0; id < edge_list_mul3[i][j].size(); id++){
                        num_edge[j]++;
                        num_edge[i]++;
                    }
                }
            }      
            return num_edge;
        }
        dt get_TotalWeight_nonvec(const vector<vector<vector<dt>>>& edge_list_mul3){
            dt total = 0;
            rep(i, n){
                rep(j, i){
                    for (int id = 0; id < edge_list_mul3[i][j].size(); id++){
                        total += edge_list_mul3[i][j][id];
                    }
                }
            }      
            return total;
        }     
        // 最短経路ペアを探索する。ﾜｰｼｬﾙﾌﾛｲﾄﾞ法O(n^3)
        vector<vector<dt>> solve_WarshallFloyd(const vector<vector<dt>>& edge_list){
            int n = edge_list.size();
            vector<vector<dt>> dp = edge_list;
            rep(i, n){
                rep(j, n){
                    if(i == j) dp[i][j]=0;
                    else dp[i][j] = edge_list[i][j];
                }
            }            
            rep(k, n){
                rep(i, n){
                    rep(j, n){
                        if(dp[i][k] != inf && dp[k][j] != inf){
                          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                        }
                    }
                }
            }
            return dp;
        }
        vector<vector<dt>> solve_WarshallFloyd(const vector<vector<vector<dt>>>& edge_list_mul3){
            int n = edge_list_mul3.size();
            vector<vector<dt>> dp =  vector<vector<dt>>(n, vector<dt>(n, inf));
            rep(i, n){
                rep(j, n){
                    for (int id = 0; id < edge_list_mul3[i][j].size(); id++){
                        dp[i][j] = min(dp[i][j], edge_list_mul3[i][j][id]);
                    }
                }
            }        
            dp = solve_WarshallFloyd(dp);
            return dp;
        }
        vector<vector<dt>> solve_WarshallFloyd(){
            return solve_WarshallFloyd(edges_mul);
        }
        // 最小重み最大マッチングを解く。
        // 全ての頂点をペアにして返す。
        vector<dt> solve_matching_minweight(vector<vector<dt>> d, int ignore_bit){
            int n = d.size();
            // ex. 1<<(n=3)で[(1000)2]、必要なのは(111)2までなので1<<nで十分
            int state_all = 1<<n;
            vector<dt> dp = vector<dt>(state_all, inf);
            // ignorebit以外が偶数じゃなければ計算できない。
            int count = 0;
            rep(i,n) if(ignore_bit&(1<<i)) count++;
            if((n-count)%2>0) return dp;

            // ビットが立ってるところはコスト0でスルー
            dp[ignore_bit] = 0;
            // nビット目までのビットDP、iビット目は要素iのマッチング済みを表す
            for(int state=0;state<1<<n;state++)
            {
                for(int from=0;from<n;from++)
                {
                    // from がマッチング済みの場合スルー
                    if(state&(1<<from))continue;
                    for(int to=from+1;to<n;to++)
                    {
                        // to がマッチング済みの場合スルー
                        if(state&(1<<to))continue;
                        // 重みを足してマッチング後の状態を作り、最小なら更新
                        dp[state|(1<<from)|(1<<to)]=min(dp[state|(1<<from)|(1<<to)],dp[state]+d[from][to]);
                    }
                }
            }
            return dp;
        }
      // ダイクストラ法でノードsからの最短経路を求める。
      vector<dt> solve_Djakstra(const vector<vector<dt>>& edge_list, const int& s){
        int n = edge_list.size();   
        priority_queue<pair<dt, int>, vector<pair<dt, int>>, greater<pair<dt, int>>> candidate_que;   
        vector<dt> distance_dp(n, inf);
        pair<dt, int> tmp_node;
        int now_index;
        // 最初にsを投入。
        candidate_que.push({0, s});
        distance_dp[s] = 0;
        // queの中の最小距離のノードに順に着目して最短経路を更新していく。
        while(!candidate_que.empty()){
          tmp_node = candidate_que.top();candidate_que.pop();
          now_index = tmp_node.second;
          rep(i, edge_list[now_index].size()){
            if(edge_list[now_index][i] == inf) continue;
            if(distance_dp[i] > distance_dp[now_index] + edge_list[now_index][i]){
              candidate_que.push({edge_list[now_index][i], i});
              distance_dp[i] = distance_dp[now_index] + edge_list[now_index][i];
            }
          }
        }
        return distance_dp;
      }
      vector<dt> solve_Djakstra_light(const int& s){  
        priority_queue<pair<dt, int>, vector<pair<dt, int>>, greater<pair<dt, int>>> candidate_que;   
        vector<dt> distance_dp(n, inf);
        pair<dt, int> tmp_node;
        int now_index;
        // 最初にsを投入。
        candidate_que.push({0, s});
        distance_dp[s] = 0;
        // queの中の最小距離のノードに順に着目して最短経路を更新していく。
        while(!candidate_que.empty()){
          tmp_node = candidate_que.top();candidate_que.pop();
          now_index = tmp_node.second;
          rep(i, edges_light[now_index].size()){
            if(distance_dp[edges_light[now_index][i].first] > distance_dp[now_index] + edges_light[now_index][i].second){
              candidate_que.push({edges_light[now_index][i].second, edges_light[now_index][i].first});
              distance_dp[edges_light[now_index][i].first] = distance_dp[now_index] + edges_light[now_index][i].second;
            }
          }
        }
        return distance_dp;
      }
      vector<dt> solve_Djakstra(const vector<vector<vector<dt>>>& edge_list_mul3, const int& s){
        int n = edge_list_mul3.size();
        vector<vector<dt>> dp =  vector<vector<dt>>(n, vector<dt>(n, inf));
        rep(i, n){
            rep(j, n){
                for (int id = 0; id < edge_list_mul3[i][j].size(); id++){
                    dp[i][j] = min(dp[i][j], edge_list_mul3[i][j][id]);
                }
            }
        }        
        return solve_Djakstra(dp, s);      
      }
      vector<dt> solve_Djakstra(const int& s){
        return solve_Djakstra(edges_mul, s);
      }
      // ベルマンフォード法
      // 頂点の回数だけ、全ての辺を使って最短距離を計算する。
      // ある頂点と頂点は、高々頂点の個数分しか離れていないので、|V|-1回繰り返せば辺がグラフ全体に伝搬するため。
      // O(VE)
      vector<dt> solve_BellmanFord_light(const int& s, bool& negative_flag){  
        negative_flag = false;
        vector<dt> distance_dp(n, inf);
        distance_dp[s] = 0;
        int to; dt cost;
        // queの中の最小距離のノードに順に着目して最短経路を更新していく。
        rep(loop_count, n){
          // toとnow_nodeで計|E|のループ
          rep(now_node, n){
            rep(to_i, edges_light[now_node].size()){
              to = edges_light[now_node][to_i].first; cost = edges_light[now_node][to_i].second;
              if(distance_dp[now_node] != inf &&distance_dp[to] > distance_dp[now_node] + cost){
                distance_dp[to] = distance_dp[now_node] + cost;
                if(loop_count == n-1) negative_flag = true;
              }
            }
          }
        }
        return distance_dp;
      }
      
      // edgeから必ず一本しか出てない場合のサイクル探索
      vector<vector<dt>> cycle_search(){
          // ループに初めて入る点、ループまでの距離、ループの重み、ループまでの移動歩数、ループの一周歩数
          vector<vector<dt>> loop_info(n, vector<dt>(5,-1));
          bool seen[n];
          dt step_count[n], step_cost[n];
          dt now, count, cost;
          rep(i,n){
            // 到達判定の初期化
            rep(j,n) seen[j] = false; 
            rep(j,n) step_cost[j] = 0; 
            rep(j,n) step_count[j] = 0; 
            now = i;
            count = 0;
            cost = 0;
            while(!seen[now]){
              seen[now] = true;
              step_cost[now] = cost; cost+= edges_light[now][0].second;
              step_count[now] = count; count++;                
              now = edges_light[now][0].first;
            }
            loop_info[i][0] = now;
            loop_info[i][1] = step_cost[now];
            loop_info[i][2] = cost - step_cost[now];
            loop_info[i][3] = step_count[now];
            loop_info[i][4] = count - step_count[now];            
          }
          return loop_info;
      }
};


int main() {
  using dt = LL;
  LL N, K; scanf("%lld %lld", &N, &K);
  vector<dt> P(N,0);
  vector<dt> C(N,0);
  // dp[i][K]　iマスにある時の最大値
  Solve_Path<dt> SP(N, INT_MAX);
  SP.enable_edges_light();
  dt p, c;
  rep(i,N){
    scanf("%lld", &p);
    P[i]=p-1;
  }
  rep(i,N){
    scanf("%lld", &c);
    C[i]=c;
  }  
  rep(i,N) SP.add_path_light(i, P[i], C[P[i]]); 
  vector<vector<dt>> cycle_info = SP.cycle_search();
  dt maxval = -INT_MAX;
  
  rep(i,N){
    dt step_count = 0;
    dt tmp_val = 0;
    dt now = i;
    // K歩以内にループできないとき
    if(K <= cycle_info[i][3]+cycle_info[i][4]){
      while(step_count<K){
        tmp_val += SP.edges_light[now][0].second;
        now = SP.edges_light[now][0].first;
        maxval = max(maxval, tmp_val);
        step_count++;
      }
    }else{
      // ループ回した方が得な場合
      if(cycle_info[i][2]>0){
        // ループ前までで最大の場所がある可能性を探す。
        while(step_count<cycle_info[i][3]){
          tmp_val += SP.edges_light[now][0].second;
          now = SP.edges_light[now][0].first;
          maxval = max(maxval, tmp_val);
          step_count++;
        }
        // 到達後、全力でループして、あとは最大になる箇所を限界まで歩いて探す
        tmp_val += cycle_info[i][2]*((K-cycle_info[i][3])/cycle_info[i][4] - 1);
        step_count += cycle_info[i][4]*((K-cycle_info[i][3])/cycle_info[i][4] - 1);
        // 0歩でここまで来る可能性がある
        if(step_count>0) maxval = max(maxval, tmp_val);
        while(step_count<K){
          tmp_val += SP.edges_light[now][0].second;
          now = SP.edges_light[now][0].first;
          maxval = max(maxval, tmp_val);
          step_count++;
        }
      }else{
        //ループ回しても徳がない場合、一周まで回る。事故ループなどクリティカルな場合、ループ回数が0になるのでmax1を取る。
        while(step_count<max((dt)1,cycle_info[i][3]+cycle_info[i][4])){
          tmp_val += SP.edges_light[now][0].second;
          now = SP.edges_light[now][0].first;
          maxval = max(maxval, tmp_val);
          step_count++;
        }    
      }
    }
  }
  if(maxval == -INT_MAX) cycle_info[1000000000];
  cout << maxval << endl;
  return 0;
}

