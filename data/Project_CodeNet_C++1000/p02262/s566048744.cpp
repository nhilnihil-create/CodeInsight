#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

void Display(std::vector<long int> ary) {
    long int n = ary.size();
    for (long int i = 0; i < n; i++) {
        std::cout << ary[i];
        if (i < n -1) {
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

std::vector<long int> GetInput() {
    long int n = -1;
    std::vector<long int> ary;
    std::cin >> n;
    ary.resize(n);
    for (long int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }
    return ary;
}


std::tuple<std::vector<long int>, long int>
    InsertionSort(std::vector<long int> ary, long int gap = 1) {
    long int cnt = 0;
    if (gap < 1) {
        std::cout << "----------" << std::endl;
        std::cout << "Invalid gap is inputted." << std::endl;
        std::cout << gap << std::endl;
        std::cout << "----------" << std::endl;
    }
    long int n = ary.size();
    for (long int i=gap; i<n; i++) {
        long int temp = ary[i];
        long int j = i - gap;
        while(j>=0 && ary[j] > temp) {
            ary[j+gap] = ary[j];
            cnt++;
            j -= gap;
        }
        ary[j+gap] = temp;
    }
    return std::tuple<std::vector<long int>, long int>(ary, cnt);
}

std::vector<long int> ShellSort(std::vector<long int> ary) {
    long int cnt = 0;
    long int n = ary.size();
    std::vector<long int> g_params;
    for (int i = 1; i <= n;) {
        g_params.push_back(i);
        i = i * 3 + 1;
    }
    std::cout << g_params.size() << std::endl;
    for (int i = g_params.size() - 1; i > 0; i--) {
        std::cout << g_params[i] << " ";
    }
    std::cout << g_params[0] << std::endl;

    for (int i = g_params.size()-1; i >= 0; i--) {
        auto result = InsertionSort(ary, g_params[i]);
        ary = std::get<0>(result);
        cnt += std::get<1>(result);
    }

    std::cout << cnt << std::endl;
    for(auto it: ary) {
        std::cout << it <<std::endl;
    }
    return ary;
}


int main(int argc, char const* argv[])
{
    auto ary = GetInput();
    auto sorted_ary = ShellSort(ary);
//     Display(sorted_ary);
    return 0;
}