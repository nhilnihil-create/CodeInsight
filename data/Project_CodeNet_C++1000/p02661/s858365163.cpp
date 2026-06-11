#include<iostream>
#include<vector>
#include<algorithm>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
	std::cin >> a[i] >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    double am, bm;
    double ans;
    if(n % 2 == 1){
	am = a[(n+1)/2 - 1];
	bm = b[(n+1)/2 - 1];
	ans = bm - am + 1;
    }else{
	am = (a[n/2 - 1] + a[n/2]);
	bm = (b[n/2 - 1] + b[n/2]);
	ans = (bm - am) + 1;
    }
    long long ans2;
    ans2 = ans + 0.1;
    std::cout << ans2 << std::endl;
    return 0;
}

