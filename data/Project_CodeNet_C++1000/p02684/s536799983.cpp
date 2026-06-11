#include<iostream>
#include<vector>
#include<set>

int main(void){
    int n;
    long long k;
    std::set<int> b;
    std::cin >> n >> k;
    std::vector<int> a(n), t(n);
    for(int i = 0; i < n; i++){
	std::cin >> a[i];
	a[i]--;
    }
    int time = 0;
    int cur = 0;
    t[cur] = 0;
    b.insert(cur);
    while(true){
	cur = a[cur];
	time++;
	if(b.find(cur) != b.end()){
	    break;
	}else{
	    t[cur] = time;
	    b.insert(cur);
	}
    }

    std::vector<int> c;
    int start = cur;
    while(true){
	c.push_back(cur);
	cur = a[cur];
	if(cur == start){
	    break;
	}
    }
    int ans;

    if(k < t[start]){
	ans = 0;
	for(int i = 0; i < k; i++){
	    ans = a[ans];
	}
    }else{
	ans = c[(k - t[start]) % c.size()];
    }
    std::cout << ++ans << std::endl;

    return 0;
}

