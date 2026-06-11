#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, k, q;
    cin >> n >> k >> q;
    vector<long long> ans(n, k);
    vector<long long> a(q);

    for(long long i = 0; i < q; i++){
        cin >> a[i];
        a[i]--;
    }

    for(long long i = 0; i < n; i++){
        ans[i] = ans[i] - q;
    }

    for(long long i = 0; i < q; i++){
        ans[a[i]]++;
    }

    for(long long i = 0; i < n; i++){
        if(ans[i] > 0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}