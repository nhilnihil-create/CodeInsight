#include <iostream>
#include <vector>

int check(std::vector<int>& A){
    int tmp=0, first = A.at(0);
    A.erase(A.begin());
    for (int i: A){
        if (i < first) ++tmp;
    }
    return tmp;
}

int main(void){
    int N, a=0, b=0, ans=0;
    std::cin >> N;
    std::vector<int> P(N);
    std::vector<int> Q(N);
    const std::vector<int> con = {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320
    };
    for (int i=0; i<N; ++i){
        std::cin >> P.at(i);
    }
    for (int i=0; i<N; ++i){
        std::cin >> Q.at(i);
    }

    for (int i=N; i>0; --i){
        a += con.at(i - 1) * check(P);
        b += con.at(i - 1) * check(Q);
    }


    std::cout << abs(a - b) << std::endl;

    return 0;
}
