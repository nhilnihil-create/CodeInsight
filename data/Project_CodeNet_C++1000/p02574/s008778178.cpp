    #include <iostream>
    #include <string>
    #include <cmath>
    using namespace std;
     
    int is_prime(int n){
        
        int i;
        i = 2;
        
        if (n == 1){
            return 0;
            
        } else if (n == 2){
            return 1;
            
        } else {
            while(1){
                if (n % i == 0){
                    return 0;
                    
                } else if (n < i * i){
                    return 1;
                    
                } else {
                    i++;
                }
            }
        }
        
        return 0;
    }
     
    int gcd(int m, int n){
        
        if (m % n == 0){
            return n;
        } else {
            return gcd(n, m % n);
        }
    }
     
    int is_set(int b[1145140], int n){
        
        int i;
        i = 2;
        
        if (n == 1) return 0;
        
        if (is_prime(n) == 1){
            if (b[n] == 1) {
                return 1;
            } else {
                b[n] = 1;
            }
            
        } else {
            while(n % i > 0){
                i++;
            }
                    
            if (b[i] == 1) {
                return 1;
                
            } else {
                b[i] = 1;
                
                while (n % i == 0){
                    n /= i;
                }
     
                return is_set(b, n);
            }
            
        }
        
        return 0;
    }
     
    int main(){
        
        int i, N, GCD, D, set;
        cin >> N;
        
        int a[N];
        int b[1145140];
        
        for (i = 0; i < N; i++){
            cin >> a[i];
        }
        
        for (i = 0; i < 100; i++){
            b[i] = 0;
        }
        
        for (i = 0; i < N; i++){
            if (i == 0){
                GCD = a[i];
                
            } else {
                D = gcd(GCD, a[i]);
                GCD = D;
            }
                    
            if (GCD == 1) break;
        }
        
        if (GCD > 1){
            cout << "not coprime\n";
            return 0;
        }
        
        for (i = 0; i < N; i++){
            set = is_set(b, a[i]);
            if (set == 1){
                cout << "setwise coprime\n";
                return 0;
            }
        }
        
        cout << "pairwise coprime\n";
        
        return 0;
    }