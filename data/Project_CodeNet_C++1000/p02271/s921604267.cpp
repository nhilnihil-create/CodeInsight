/* ALDS1_5_A: Exhaustive Search */

#include <iostream>
#include <string>

int N;
int *S;

bool find(int i, int goal) {
    if (goal == 0)
        return true;
    if (i == N)
        return false;
    return find(i + 1, goal - S[i]) || find(i + 1, goal);
}

int main() {
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    S = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> S[i];

    int n_goals;
    std::cin >> n_goals;

    int goal;
    std::string *results = new std::string[n_goals];
    for (int i = 0; i < n_goals; i++) {
        std::cin >> goal;
        results[i] = find(0, goal) ? "yes" : "no";
    }

    for (int i = 0; i < n_goals; i++) {
        std::cout << results[i] << "\n";
    }
}