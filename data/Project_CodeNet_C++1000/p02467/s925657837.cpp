#include <iostream>
#include <vector>
int n;
std::vector<int> prime;
bool isprime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i*i <=n; i+=2){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    std::cin >> n;
    std::vector<int> prime;
    for(int i = 2; i*i <= n; i++){
        if(isprime(i)) prime.push_back(i);
    }
    std::vector<int> ans;
    int t = n;
    while(n != 1){
        if(isprime(n)){
            ans.push_back(n);
            break;
        }
        else{
            for(int i: prime){
                if(n % i == 0) {
                    ans.push_back(i);
                    n /= i;
                    break;
                }
            }
        }
    }
    printf("%d:", t);
    for(int i: ans) printf(" %d", i);
    printf("\n");
}
