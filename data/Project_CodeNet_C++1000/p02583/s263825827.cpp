#include <iostream>

const int maxn = 1e2 + 5;
long long seq[maxn];
int main(){
    int n;
    std::cin >> n;
    for (int i= 1; i <= n; ++ i) std::cin >> seq[i];
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            for (int k = 1; k <= n; ++ k){
                if (i == j || j == k || i == k) continue;
                if (seq[i] == seq[j] || seq[j] == seq[k] || seq[i] == seq[k]) continue;
                if (seq[i] + seq[j] > seq[k] && seq[i] + seq[k] > seq[j] && seq[j] + seq[k] > seq[i]){
                    cnt ++;
                }
            }
        }
    }
    std::cout << cnt / 6 << std::endl;
}