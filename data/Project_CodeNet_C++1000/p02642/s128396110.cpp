#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    long long N;
    std::cin >> N;
    std::vector<long long> A(N,0);
    for(long long i=0;i<N;i++){
        std::cin >> A[i];
    }
    std::vector<bool> psb(N,true);

    std::sort(A.begin(),A.end());

    long long cnt=0;
    for(long long i=0;i<N;i++){
        if(psb[i] == true) {
            cnt++;

            for (long long j = 1; A[i] * j <= A[N-1]; j++) {
                auto itrFound_left = std::lower_bound(A.begin()+i+1, A.end(), A[i] * j) ;
                auto itr_Found_right = std::upper_bound(A.begin()+i+1, A.end(), A[i] * j) ;
                if (*itrFound_left == A[i]*j) {
                    for(long long k=itrFound_left - A.begin();k<itr_Found_right - A.begin();k++) {
                        psb[k] = false;
                    }
                }
                if(*itrFound_left == A[i]){
                    psb[i] = false;
                    cnt --;
                }
            }
        }
    }
    std::cout << cnt;
    return 0;
}

