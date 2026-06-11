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
using namespace std;
const double pi = acos(-1.0);
int main()
{
    int d;
    scanf("%d", &d);
    if (d % 2 != 0){
        cout<<abs((d/2)+1)<<"\n";
    }
    else{
        cout<<abs(d/2)<<"\n";
    }
    return 0;
}