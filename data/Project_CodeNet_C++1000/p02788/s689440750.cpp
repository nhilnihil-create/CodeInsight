#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

int main(void){
    long long n, d, a, x, h;
    std::cin >> n >> d >> a;
    std::vector<std::pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
	std::cin >> x >> h;
	p[i].first = x;
	p[i].second = h;
    }
    std::sort(p.begin(), p.end());
    long long ans = 0;

    std::queue<std::pair<int, int>> q;
    long long tot = 0;
    for(int i = 0; i < n; i++){
	while(q.size() != 0 && p[i].first > q.front().first){
	    tot -= q.front().second;
	    q.pop();
	}
	h = p[i].second - tot;
	if(h > 0){    	
	   int num = (h + a - 1) / a;
	   ans += num;
    	   long long damage = a * num;
    	   q.push(std::make_pair(p[i].first + 2 * d, damage));
	   tot += damage;
	}
    }
    std::cout << ans << std::endl;

    return 0;
}

