#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 200000;

int main(){
    int N;
    char c[MAX];

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> c[i];
    }

    int l = 0;
    int r = N - 1;
    int ans = 0;

    while(true){
        while(l < N && c[l] != 'W')l++;
        while(r >= 0 && c[r] != 'R')r--;
        if(l >= r)break;
        swap(c[l],c[r]);
        ans++;
    }

    cout << ans << endl;

    return 0;
}