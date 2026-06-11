#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int n;
int ar[N];
map < int , int > cnt;

int main(){
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &ar[i]);
        cnt[i - ar[i]]++;
    }
    long long ways = 0;
    for(int i = 1; i <= n; i++){
        cnt[i - ar[i]]--;
        ways += cnt[ar[i] + i];
        cnt[i - ar[i]]++;
    }
    printf("%lld\n" , ways);

}
