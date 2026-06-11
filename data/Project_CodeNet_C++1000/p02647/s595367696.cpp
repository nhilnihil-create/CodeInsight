#include <bits/stdc++.h>

//#define DEBUG

using namespace std;

template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}


void solve(){
    int32_t N, K ;
    cin >> N >> K;
    std::vector<int32_t> A;
    A.reserve(N);
    std::vector<int32_t> B (N + 1, 0);
    for(int32_t i = 0 ; i < N ; i++){
        uint32_t a;
        cin >> a;
        A.push_back(a);
    }
    K = std::min(K, 100);
    for(int32_t l = 0 ; l < K ; l++){
        //usig accumlate technique
        std::fill(B.begin(), B.end(), 0);
        for(int32_t i = 0 ; i < N ; i++){
            int left, right;
            if( A[i] > 0){
                left = std::max(0 , i - A[i]);
                right = std::min(i + A[i], N - 1);
            }else{
                left = i;
                right = i;
            }
            B[left] = B[left] + 1;
            B[right + 1] = B[right + 1] - 1;
        }
        int32_t accumulate = 0;
        for(int32_t i = 0 ; i < N ; i++){
            accumulate += B[i];
            A[i] = accumulate;
        }
    }
    print_vect(A);
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}
