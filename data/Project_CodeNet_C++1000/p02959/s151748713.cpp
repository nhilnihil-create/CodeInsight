#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n+1), b(n);
    for(int i = 0; i < n+1; i++){
        std::cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        std::cin >> b[i];
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= b[i]){
            ans += b[i];
        }else{
            if(b[i] - a[i] >= a[i+1]){
                ans += a[i] + a[i+1];
                a[i+1] = 0;
            }else{
                ans += b[i];
                a[i+1] -= b[i] - a[i];
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}