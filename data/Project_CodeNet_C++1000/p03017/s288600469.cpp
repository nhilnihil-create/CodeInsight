#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll x, ll y) {
    return x / GCD(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--; B--; C--; D--;

    string S;
    cin >> S;
    bool ans = true;
    if (C < D)
    {
        for (int i = A; i < D; i++)
        {
            if (S[i] == '#' && S[i + 1] == '#')
            {
                cout << "No" << endl;
                return 0;
            }
             
        }
        cout << "Yes" << endl;
        return 0;
        
    }else if (C > D)
    {
        
        for (int i = A; i < C; i++)
        {
             if (S[i] == '#' && S[i + 1] == '#')
            {
                cout << "No" << endl;
                return 0;
            }
            
        }
        for (int i = B - 1; i < D; i++)
        {
            if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.')
            {
                cout << "Yes" << endl;
                return 0;
            }
            
        }
        
        cout << "No" << endl;
        
    }

    
    
    
    
    
     
    return 0;

}
