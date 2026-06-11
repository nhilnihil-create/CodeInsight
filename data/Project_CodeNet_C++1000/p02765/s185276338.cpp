////////////////////////////////////////////////
//  ********  *      *    *******    * *      //                 :
//  *         *      *   *       *   *   *    //     64 BITS     C     64 BITS
//  *****     *      *  *         *  *     *  //                 +
//  *         *      *  ***********  *     *  //:  16 - 6 - 2020 +   16 - 6 - 2020 :
//  *         *      *  *         *  *   *    //                 1
//  *         ********  *         *  * *      //     64 BITS     7     64 BITS
////////////////////////////////////////////////                 :
#define ll long long
#define ui unsigned int
#define ud unsigned double
#define mp make_pair
#define pii pair<int,int>
#define pci pair<char,int>
#define pic pair<int,char>
#define pdi pair<double,int>
#define pb push_back
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
const double pi = acos(-1.0);
int main()
{
    int b;
    int g;
    scanf("%d%d", &b,&g);
    if (b <= 10){
        cout<<g+(100*(10-b))<<"\n";
    }
    else{
        cout<<g<<"\n";
    }
    return 0;
}