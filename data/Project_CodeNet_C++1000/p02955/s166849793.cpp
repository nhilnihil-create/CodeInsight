/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;

int n;
int k;
int sum;
int a[N];

int b[N];

bool can(int d){
    for(int i = 1; i <= n; i++){
        b[i] = a[i] % d;
    }
    sort(b + 1 , b + n + 1);
    int i = 1;
    int j = n;
    int stp = 0;
    int now = 0;
    while(i <= j){
        if(stp <= 0){
            stp += b[i];
            now += b[i];
            i++;
        } else {
            stp -= d - b[j];
            j--;
        }
    }
    if(stp == 0)
        return now <= k;
    return 0;
}

int main(){
    scanf("%d%d" , &n , &k);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &a[i]);
        sum += a[i];
    }
    int ans = 0;
    for(int i = 1; i*i <= sum; i++){
        if(sum % i == 0){
            if(can(i)){
                ans = max(ans , i);
            }
            if(can(sum / i)){
                ans = max(ans , sum / i);
            }
        }
    }
    printf("%d\n" , ans);
}
