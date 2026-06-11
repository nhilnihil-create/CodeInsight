/*
Problem Number: ABC177E
Problem Name: Coprime
Notes: 
*/

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int sp[int(1e6)+1];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int gcd = a[0];
    for(int i = 1; i < n; i++)
        gcd = __gcd(gcd, a[i]);
    if(gcd > 1){
        cout << "not coprime" << endl;
        return 0;
    }

    memset(sp, 0, sizeof(sp));
    for(int i = 2; i < int(1e6)+1; i++)
        if(!sp[i])
            for(int j = i; j < int(1e6)+1; j+=i)
                if(!sp[j])
                    sp[j] = i;

    bool primes[int(1e6)];
    memset(primes, 0, sizeof(primes));
    for(int i = 0; i < n; i++){
        int ai = a[i];
        while(ai != 1){
            int spi = sp[ai];
            if(primes[spi]){
                cout << "setwise coprime" << endl;
                return 0;
            }
            primes[spi] = 1;
            while(ai % spi == 0)
                ai /= spi;
        }
    }

    cout << "pairwise coprime" << endl;
    
    return 0;
}