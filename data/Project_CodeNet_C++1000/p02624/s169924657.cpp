#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    long long ans=0, ans_save;
    long num=0;
    for(int i=1;i<n+1;i++){
        num = n/i;
        // cout << num << endl;
        ans_save = i*(num)*(num+1)/2;
        ans += ans_save;
    }
    cout << ans << endl;
}