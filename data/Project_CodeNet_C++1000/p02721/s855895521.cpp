#include <iostream>
#include <vector>
#include <string>

int main(){
    int N, K, C;
    std::cin >> N >> K >> C;
    std::string s;
    std::cin >> s;
    std::vector<int> work_day;
    int last_work = - C - 1;
    bool ok = false;
    for(int i = 0; i < N; ++i){
        if(s[i] == 'o' && i > last_work + C){
            work_day.push_back(i);
            last_work = i;
        }
        if((int)work_day.size() >= K){
            ok = true;
            break;
        }
    }
    if(!ok) return 0;
    std::vector<int> dp(N+1);
    dp[N] = 0;
    last_work = N + C;
    for(int i = N - 1; i >= 0; --i){
        if(s[i] == 'o' && i < last_work - C){
            dp[i] = dp[i+1] + 1;
            last_work = i;
        }else{
            dp[i] = dp[i+1];
        }
    }
    std::vector<int> ans;
    for(int i = 0; i < (int)work_day.size(); ++i){
        const int day = work_day[i];
        if(i + dp[day + 1] < K) ans.push_back(day);
    }
    for(const int day : ans){
        std::cout << day + 1 << "\n";
    }
}