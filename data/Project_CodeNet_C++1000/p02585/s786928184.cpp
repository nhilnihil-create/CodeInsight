#include <bits/stdc++.h>
using namespace std;
 
long long getAnswer(vector< int >& cycle, int* c, int k){
    int lengthOfCycle = cycle.size();
    long long totalSum = 0;
    for(int u : cycle){
        totalSum += c[u];
    }
    int roundTrips = k / lengthOfCycle;
    int remaining = k % lengthOfCycle;
    long long answer = LLONG_MIN;
    if(roundTrips > 1){
        if(totalSum >= 0){
            remaining += lengthOfCycle;
            long long tmp = totalSum * (roundTrips - 1);
            for(int i = 0; i < lengthOfCycle; i++){
                int start = i;
                long long candidate = 0;
                for(int moves = 0; moves < remaining; moves++){
                    answer = max(answer, tmp + candidate);
                    candidate += c[cycle[(start + 1) % lengthOfCycle]];
                    start++;
                }
                answer = max(answer, tmp + candidate);
            }
        }
        else{
            for(int i = 0; i < lengthOfCycle; i++){
                long long candidate = 0;
                int start = i;
                for(int moves = 0; moves < lengthOfCycle; moves++){
                    candidate += c[cycle[(start + 1) % lengthOfCycle]];
                    answer = max(answer, candidate);
                    start++;
                }
            }
        }
    }
    else{
        for(int i = 0; i < lengthOfCycle; i++){
            long long candidate = 0;
            int start = i;
            for(int moves = 0; moves < k; moves++){
                candidate += c[cycle[(start + 1) % lengthOfCycle]];
                answer = max(answer, candidate);
                start++;
            }
        }
    }
    return answer;
 
}
 
int main(){
    int n, k; cin >> n >> k;
    int p[n];
    int *c = new int[n];
    for(int& u : p){
        cin >> u;
        --u;
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    bool vis[n]; memset(vis, false, sizeof(vis));
    long long answer = LLONG_MIN;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vector< int > cycle;
            while(!vis[i]){
                vis[i] = true;
                cycle.push_back(i);
                i = p[i];
            }
            long long candidate = getAnswer(cycle, c, k);
            answer = max(answer, candidate);
        }
    }
    cout << answer << '\n';
    return 0;
}
