#include <iostream>
#include <vector>
#include <algorithm>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int N, ans = 0;
    std::cin >> N;

    std::vector<int> L(N);
    for(int i = 0; i < N; i++) {
        std::cin >> L.at(i);
    }

    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            for(int k = j + 1; k < N; k++) {
                
                if(L.at(i) != L.at(j) && L.at(i) != L.at(k) && L.at(j) != L.at(k)) {
                    int a = L.at(i), b = L.at(j), c = L.at(k);

                    if(a > c) {
                        swap(&a, &c);
                    }
                    if(b > c) {
                        swap(&b, &c);
                    }

                    if(a + b > c) {
                        ans++;
                    }
                }
                
            }
        }
    }

    std::cout << ans << std::endl;

}
