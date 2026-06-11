#include<iostream>
#include<vector>

int main(void){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    int l = 1, r = 1e9;
    while(l < r){
        int mid = (l + r) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += (a[i] - 1) / mid;
        }
        if(cnt > k){
            l = mid + 1;
        }else{
            r = mid;
        }
    }

    std::cout << r << std::endl;
    return 0;
}
