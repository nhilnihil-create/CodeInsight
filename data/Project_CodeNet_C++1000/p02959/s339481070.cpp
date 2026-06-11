#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n);
    for(int i = 0; i < n + 1; i++) std::cin >> a[i];
    for(int i = 0; i < n; i++) std::cin >> b[i];

    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= b[i]){
            sum += a[i];
            b[i] -= a[i];
            a[i] = 0;
            
            if(a[i + 1] >= b[i]){
                sum += b[i];
                a[i + 1] -= b[i];
                b[i] = 0;
            }else{
                sum += a[i + 1];
                b[i] -= a[i + 1];
                a[i + 1] = 0;
            }
        }else{
            sum += b[i];
            a[i] -= b[i];
            b[i] = 0;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
