
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : August 21, 2020 12:28 PM
 *    Problem Name  : C - Maximal Value
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc140/tasks/abc140_c
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int b[n+1];
    int sum = 0;

    for(int i=0; i<n-1; i++){
        cin >> b[i];
    }

    vector<int>v;
    v.push_back(b[0]);

    for(int i=1; i<n-1; i++){
        v.push_back(min(b[i],b[i-1]));
    }

    v.push_back(b[n-2]);

    for(int i=0; i<v.size(); i++){
        sum+=v[i];
    }

    cout << sum << endl;

    return 0 ;
}
