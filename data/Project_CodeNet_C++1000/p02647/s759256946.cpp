#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


vector<long long> count_v(vector<long long> v){
    long long n = v.size();

    vector<long long> ans(n, 0);
    for(long long i = 0; i < n; i++){
        long long left = max((long long)0, i-v[i]);
        long long right = min(n-1, i+v[i]);
        ans[left]++;
        if(right+1 < n){
            ans[right+1]--;
        }
        
    }

    for(long long i = 1; i < n; i++){
        ans[i] += ans[i-1];
    }

    return ans;
}
int main(){
    long long n ,k;
    cin >> n >> k;

    vector<long long> a(n);
    vector<long long> ans_n(n, n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    

    for(long long i = 0; i < k; i++){
        a = count_v(a);
        if(a == ans_n){
            for(long long j = 0; j < n; j++){
                printf("%lld ", n);
            }
            printf("\n");
            return 0;
        }
    }

    for(long long i = 0; i < n; i++){
        printf("%lld ", a[i]);
    }

    printf("\n");

    return 0;

}