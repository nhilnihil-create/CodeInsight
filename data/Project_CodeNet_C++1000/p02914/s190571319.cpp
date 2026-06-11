#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    long long int total_xor = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        total_xor ^= a[i];
    }
    for(int i=0; i<n; i++){
        a[i] &= ~total_xor;// ~ : NOT, ignoring the bits having no effect
    }

    // Gaussian Elimination (XOR ver.)
    int rank = 0;
    vector<int> msb(n);
    for(int b=60; b>=0; b--){
        bool flag = false;
        for(int i=rank+1; i<n; i++){
            if(a[i] >> b & 1){// if bit set
                swap(a[i], a[rank]);
                flag = true;
                break;
            }
        }
        if(flag == false) continue;// no bit set

        msb[rank] = b;
        for(int i=0; i<n; i++){
            if(i == rank) continue;

            if(a[i] >> b & 1) a[i] ^= a[rank];// eliminate
        }
        rank += 1;
    }
    
    long long int max_and = 0;
    for(int b=60; b>=0; b--){
        long long int test = max_and | (1LL << b);// *...*10...0

        for(int i=0; i<rank; i++){
            if(test >> msb[i] & 1) test ^= a[i];
        }
        
        bool flag = true;
        for(int c=60; c>=b; c--){
            if(test >> c & 1) flag = false;
        }
        if(flag == true) max_and |= (1LL << b);
    }
    cout << total_xor + 2 * max_and << endl;// (a + b) = (a XOR b) + 2 * (a AND b)
    return 0;
}