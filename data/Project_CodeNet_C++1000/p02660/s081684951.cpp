#include<iostream>
#include<vector>
#include<cmath>

int main(void){
    long long n;
    std::cin >> n;
    int rn = std::sqrt(n);
    std::vector<int> a, b;

    for(int i = 2; i <= rn; i++){
	int cnt = 0;
	bool flag = 0;
	while(true){
	    if(n % i != 0){
		break;
	    }else{
		n /= i;
		cnt++;
		flag = 1;
	    }
	}
	if(flag){
	    a.push_back(i);
	    b.push_back(cnt);
	}
    }
    if(n != 1){
	a.push_back(n);
	b.push_back(1);
    }

    // for(int i = 0; i < a.size(); i++){
    //     if( i != 0 ) std::cout << " * ";
    //     std::cout << a[i] << "^" << b[i];
    // }
    // std::cout << std::endl;
    //
    long long ans = 0;
    for(int i = 0; i < a.size(); i++){
	int j = 1;
	while(true){
	    if(b[i] >= j){
		b[i] -= j;
		j++;
		ans++;
	    }else{
		break;
	    }

	}
    }

    std::cout << ans << std::endl;

    return 0;
}
