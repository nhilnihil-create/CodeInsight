#include<iostream>
#include<vector>

int n, m, q;
int ans;
std::vector<int> a, b, c, d;

void dfs(std::vector<int> A, int cnt){
    if(cnt == n){
        int tmp = 0;
        for(int i = 0; i < q; i++){
            if(A[b[i]] - A[a[i]] == c[i]){
                tmp += d[i];
            }
        }
        ans = std::max(ans, tmp);
        return;
    }

    A.push_back(A.back());
    while(A.back() <= m){
        dfs(A, cnt+1);
        A.back()++;
    }
}

int main(void){
    std::cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for(int i = 0; i < q; i++){
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    std::vector<int> A = {1};
    dfs(A, 0);
    std::cout << ans << std::endl;
    return 0;
}
