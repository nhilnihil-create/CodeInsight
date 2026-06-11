
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : August 21, 2020 12:28 PM
 *    Problem Name  : B - Buffet
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc140/tasks/abc140_b
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int a[n+1] , b[n+1], c[n+1];
    int sum = 0;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        cin >> b[i];
        sum+=b[i];
    }

    for(int i=0; i<n-1; i++){
        cin >> c[i];
    }

    for(int i=0; i<n-1; i++){
        if(a[i]+1 == a[i+1]){
            sum += c[a[i]-1];
        }
    }
    cout << sum << endl;
    return 0 ;
}
