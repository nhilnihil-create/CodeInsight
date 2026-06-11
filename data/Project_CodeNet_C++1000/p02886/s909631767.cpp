#include<iostream>
#include<vector>

int n;
long long total;
std::vector<int> d;
std::vector<int> cur;
int k = 2;

void combination_cnt(int start, int cnt){
    if(cnt == k){
        total += d[cur[0]] * d[cur[1]];
        return;
    }
    for(int i = start; i < n; i++){
        cur.push_back(i);
        combination_cnt(i+1, cnt+1);
        cur.pop_back();
    }
}

int main(void){
    std::cin >> n;
    d.resize(n);
    for(int i = 0; i < n; i++){
        std::cin >> d[i];
    }
    combination_cnt(0, 0);
    std::cout << total << std::endl;

    return 0;
}