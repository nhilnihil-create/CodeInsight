#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <random>
#include <string.h>      //文字列の代入に使う
#include <bits/stdc++.h> //piの利用で必要(M_PI)
#include <algorithm>
#include <climits>
#define rep(i, c) for (int i = 0; i < (int)c; i++) //atcoderの解説コードに利用されていたので，ある程度一般生があるかと思われる．
#define ll long long

int main()
{
    int a1, a2, a3;
    std::cin >> a1 >> a2 >> a3;
    if (a1 + a2 + a3 >= 22)
    {
        std::cout << "bust" << std::endl;
    }
    else
    {
        std::cout << "win" << std::endl;
    }

    return 0;
}
