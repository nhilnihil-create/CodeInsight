#include<iostream>
#include<vector>
#include<algorithm>

int main(void){
    int n;
    long long ans = 0;
    std::cin >> n;
    std::vector<int> l(n);
    for(int i = 0; i < n; i++){
        std::cin >> l[i];
    }

    std::sort(l.begin(), l.end());

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int v = l[i] + l[j];
            auto cs = l.begin() + j + 1;
            auto it = std::lower_bound(cs, l.end(), v);
            ans += it - cs;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}