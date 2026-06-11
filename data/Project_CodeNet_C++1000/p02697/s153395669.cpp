#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isprime(int n){
    double rootn = sqrt(n);
    if (n < 2){
        return false;
    }
    else if (n == 2){
        return true;
    }
    else if (n % 2 == 0){
        return false;
    }
    else{
        for(int i = 3; i <= rootn; i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}


signed main(){
    int N, M;
    cin >> N >> M;

    int odd_end = M+1;
    int even_begin = M+2, even_end = M+2+M-1;
    if(M % 2 == 0){
        odd_end = M;
        even_begin = M+1;
        // even_end = M+1+M;
    }

    int odd_begin = 1;
    while(odd_end - odd_begin > 0){
        cout << odd_begin << " " << odd_end << endl;
        odd_begin++;
        odd_end--;
    }

    while(even_end - even_begin > 1){
        cout << even_begin << " " << even_end << endl;
        even_end--;
        even_begin++;
    }

    return 0;
}
