/* ALDS1_5_A: Exhaustive Search */

#include <iostream>
#include <string>

const int MAX_GOAL = 2000;

int N;
int *S;

void prepare(int makables[], int i, int sum) {
    if (sum <= MAX_GOAL) {
        makables[sum] = true;
        if (i == N) return;
        prepare(makables, i + 1, sum);
        prepare(makables, i + 1, sum + S[i]);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    S = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> S[i];

    int makables[MAX_GOAL + 1] = {};
    prepare(makables, 0, 0);

    int n_goals;
    std::cin >> n_goals;

    int goal;
    for (int i = 0; i < n_goals; i++) {
        std::cin >> goal;
        std::cout << ( makables[goal] ? "yes" : "no" ) << "\n";
    }
}