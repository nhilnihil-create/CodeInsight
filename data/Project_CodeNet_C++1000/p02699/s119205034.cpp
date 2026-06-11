////////////////////////////////////////////////
//  ********  *      *    *******    * *      //                 :
//  *         *      *   *       *   *   *    //     64 BITS     C     64 BITS
//  *****     *      *  *         *  *     *  //                 +
//  *         *      *  ***********  *     *  //:  13 - 6 - 2020 +   13 - 6 - 2020 :
//  *         *      *  *         *  *   *    //                 1
//  *         ********  *         *  * *      //     64 BITS     7     64 BITS
////////////////////////////////////////////////                 :
#define ll long long
#define ui unsigned int
#define ud unsigned double
#define mp make_pair
#define pii pair<int, int>
#define pb push_back
#define pi acos(-1.0)
#define eps 1e-12
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int scala;
    int php;
    scanf("%d%d", &scala,&php);
    if (php >= scala){
        puts("unsafe\n");
    }
    else{
        puts("safe\n");
    }
    return 0;
}