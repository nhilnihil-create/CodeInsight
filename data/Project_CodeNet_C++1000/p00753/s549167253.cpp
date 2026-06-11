#include <iostream>
#include <cstdio>

using namespace std;

main(){
    int a[400000] = {0};

    for(int i = 3 ; i <= 300000 ; i+=2){
        if(a[i] == 0){
            for(int j = i+i ; j <= 400000 ; j+=i){
                a[j] = 1;
            }
        }
    }

    int n;

    while(cin >> n){
        if(n == 0) break;

        int ans = 0;
        for(int i = n+1 ; i <= 2*n ; i++){
            if(i == 2) ans++;
            else if(i % 2 == 1 && a[i] == 0) ans++;
        }

        cout << ans << endl;
    }
    return 0;
}