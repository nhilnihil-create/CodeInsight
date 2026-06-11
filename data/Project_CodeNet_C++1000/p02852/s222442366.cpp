#include<iostream>
#include<vector>
#include<queue>

const static int INF = 1001001001;

int main(void){
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;
    std::queue<int> q;
    std::vector<int> dp(n+1, INF);
    
    dp[n] = 0;
    q.push(0);
    for(int i = n-1; i >= 0; i--){
	while(1){
	    if(q.empty()){
		std::cout << -1 << std::endl;
		return 0;
	    }
	    int cur = q.front();
	    // std::cout << cur << " " << q.size() << std::endl;
	    if(q.front() != INF && q.size() <= m) break;
	    q.pop();
	}
	if(s[i] == '0') dp[i] = q.front() + 1;
	q.push(dp[i]);
    }

    int x = 0;
    std::vector<int> ans;
    while(x < n){
	int res = dp[x];
	res--;
	int i = 1;
	while(dp[x + i] != res) i++;
	x += i;
	ans.push_back(i);
    }
    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    
    return 0;
}

