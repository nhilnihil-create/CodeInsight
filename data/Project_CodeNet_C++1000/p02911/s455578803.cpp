#include<iostream>
#include<vector>
#include<string>

int main(){
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<int> a(q);
    std::vector<int> point(n, k - q);
    for(int i = 0; i < q; i++){
        std::cin >> a[i];
        a[i]--;
        point[a[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(point[i] > 0){
            std::cout << "Yes" << std::endl;
        }else{
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
