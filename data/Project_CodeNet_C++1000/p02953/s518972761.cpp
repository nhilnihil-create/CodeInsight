#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long h[n];

    for(long long i = 0; i < n; i++){
        cin >> h[i];
    }

    bool flag = true;
    for(long long i = 0; i <= n-1; i++){
        if(i>0){
            if(h[i-1] == h[i] + 1){
                h[i]++;
            }
            else if(h[i-1] > h[i] + 1){
                flag = false;
                break;
            }
        }
    }

    if(flag == true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}