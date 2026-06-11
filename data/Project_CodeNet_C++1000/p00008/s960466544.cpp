#include <iostream>

int sumOf2_upTo18(int sum);
int sumOf2_upTo9(int sum);

int main()
{
    int sum;
    while (std::cin >> sum) {
        int cnt = sumOf2_upTo18(sum);
        std::cout << cnt << std::endl;
    }

    return 0;
}

int sumOf2_upTo18(int sum)
{
    int cnt = 0;
    for (int k = 0; k <= 18; k++) {
        int l = sum - k;
        if (l >= 0 && l <= 18) {
            int cnt_k = sumOf2_upTo9(k);
            int cnt_l = sumOf2_upTo9(l);
            cnt += cnt_k * cnt_l;
        }
    }

    return cnt;
}

int sumOf2_upTo9(int sum)
{
    int cnt = 0;
    for (int a = 0; a <= 9; a++) {
        int b = sum - a;
        if (b >= 0 && b <= 9) {
            cnt++;
        }
    }

    return cnt;
}