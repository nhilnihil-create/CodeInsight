#include <bits/stdc++.h>
using namespace std;
 
void Main()
{
    long n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    if(p == 2 || p == 5){
        long sum = 0;
        for (long i = 0; i < n; i++)
        {
            if((s[i] - '0') % p == 0){
                sum += (long)i+1;
            }
        }
        cout << sum << endl;
    }else{
        vector<long> sm(s.size()+1); // sの下i桁の数 % p
        vector<long> cm(p); // i = sの下i桁の数 % p となる数
        sm[0] = 0;
        cm[0] = 1;
        long e = 1;
        for (long i = 1; i <= s.size(); i++)
        {
            sm[i] = (((s[s.size()-i] - '0') * e) % p + sm[i-1]) % p;
            cm[sm[i]]++;
            e = (e * 10) % p;
        }
        long sum = 0;
        for (long i = 0; i < p; i++)
        {
            if(cm[i] >= 2)
                sum += (long)cm[i] * (cm[i]-1) / 2;
        }
        cout << sum << endl;
    }

    // s[i..j] % p == 0 % p
    // (s[i..n] - s[j..n]) / 10^(n-j) % p == 0 % p
    // (s[i..n] % p) - (s[j..n] % p) == 0 % p
    // s[i..n] % p == s[j..n] % p
    
}
 
int main(int argc, char **argv)
{
    Main();
    return 0;
}