#include <bits/stdc++.h>

long long gcd(long long a_in, long long b_in){
    long long a = a_in;
    long long b = b_in;
    if(a < b){
        std::swap(a, b);
    }
    while(b != 0){
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector< int > A_in(N);
    for(int i=0; i<N; i++){
        std::cin >> A_in[i];
    }
    std::sort(A_in.begin(), A_in.end());
    std::vector< int > A;
    int remove_num = 0;
    int pre = 0;
    int n2 = -1;
    for(int i=0; i<N; i++){
        int n2_cnt = 0;
        int a_test = A_in[i];
        while(a_test % 2 == 0){
            a_test /= 2;
            n2_cnt++;
        }
        if(i == 0){
            n2 = n2_cnt;
        }else{
            if(n2 != n2_cnt){
                std::cout << 0 << std::endl;
                return 0;
            }
        }
        if(A_in[i] != pre){
            A.push_back(A_in[i] / 2);
        }else{
            remove_num++;
        }
        pre = A_in[i];
    }
    N -= remove_num;
    
    long long gcd_num = A[0];
    for(int i=1; i<N; i++){
        gcd_num = gcd_num * (long long)A[i] / gcd(gcd_num, (long long)A[i]);
        if(gcd_num > 2 * (long long)M){
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    
    
    int ans = ((long long)M + gcd_num) / (gcd_num * 2);
    
    std::cout << ans << std::endl;
    
    return 0;
}
    

