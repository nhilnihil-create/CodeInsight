
/**
 *    author        : Trisha 
 *    created       : July 11, 2020 2:07 PM
 *    Problem Name  : A - The Number of Even Pairs
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc159/tasks/abc159_a
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    int sum=0;

    for(int i=1; i<n; i++){
        sum = sum + i;
    }

    for(int i=1; i<m; i++){
        sum = sum + i;
    }
    cout << sum << endl;

    return 0 ;
}
