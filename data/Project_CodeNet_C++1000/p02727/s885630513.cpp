#include<iostream>
#include<vector>
#include<algorithm>
int main(void){
    int x, y, a, b, c;
    std::cin >> x >> y >> a >> b >> c;
    std::vector<int> p(a), q(b), r(c);
    for(int i = 0; i < a; i++){
	std::cin >> p[i];
    }
    for(int i = 0; i < b; i++){
	std::cin >> q[i];
    }
    for(int i = 0; i < c; i++){
	std::cin >> r[i];
    }
    std::sort(p.rbegin(), p.rend());
    std::sort(q.rbegin(), q.rend());
    std::sort(r.rbegin(), r.rend());
    int ai = 0, bi = 0, ci = 0;
    int sum = x + y;
    long long ans = 0;
    while(true){
	int max = 0;
	max = std::max(p[ai], q[bi]);
	max = std::max(max, r[ci]);
	if(r[ci] == max){
	    ans += r[ci];
	    ci++;
	}else if(p[ai] == max){
	    if(ai == x){
		p[ai] = 0;
		continue;
	    }else{
		ans += p[ai];
		ai++;
	    }
	}else{
	    if(bi == y){
		q[bi] = 0;
		continue;
	    }else{
		ans += q[bi];
		bi++;
	    }
	}
	if(ai + bi + ci == sum){
	    break;
	}

    }
    std::cout << ans << std::endl;
    return 0;
}

