
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : September 11, 2020 3:22 PM
 *    Problem Name  : A - Poor
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc155/tasks/abc155_a
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int a,b,c;
    cin >> a >> b >> c;

    if((a == b && b == c && c == a) || (a != b && b != c && c != a)) cout << "No" << endl;
    else cout << "Yes" << endl;



    return 0 ;
}
