
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : July 11, 2020 9:50 PM
 *    Problem Name  : A - Duplex Printing
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc157/tasks/abc157_a
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if(n%2==0)
        cout << n/2 << endl;
    else cout << (n/2)+1 << endl;

    return 0 ;
}
