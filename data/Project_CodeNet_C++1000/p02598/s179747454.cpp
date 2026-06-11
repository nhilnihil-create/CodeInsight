#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int n;
int k;
int len[N];

bool can(int x){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += (len[i] - 1) / x;
    }
    return cnt <= k;
}

int main(){
    scanf("%d%d" , &n , &k);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &len[i]);
    }
    int l = 1 , r = 1e9;
    while(l < r){
        int mid = (l + r) >> 1;
        //cout << mid << "\n";
        if(can(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    /*for(int i = 1; i < 10; i++){
        cout << i << " " << can(i) << "\n";
    }*/
    printf("%d\n" , l);
}
