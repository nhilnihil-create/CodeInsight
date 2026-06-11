/* 
 * Project: AtCoder Beginners Contest 150 C - Next Prime
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/23
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cmath>
using namespace std;

int x;

void solve() {

    if (x == 2 || x == 3) {
        printf("%d\n", x);
        return;
    }

    int num = x;
    while (true) {
        bool is_prime = true;
        if (num % 2 == 0)
            is_prime = false;
        for (int i=3;i*i<=num;i+=2) {
            if (num%i == 0) {
                is_prime = false;
            }
        }
        if (is_prime) {
            printf("%d\n", num);
            return;
        }
        if (num%2 == 0)
            num++;
        else
            num += 2;
    }
    
}

int main() {

    scanf("%d", &x);

    solve();

}
