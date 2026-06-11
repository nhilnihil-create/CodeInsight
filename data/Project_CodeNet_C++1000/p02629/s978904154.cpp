    #include <bits/stdc++.h>

    using namespace std;

    int main(){
        long long N ;
        cin >> N;
        string res;
        // N--;
        while (N > 0) {
            N--;
            // int t = N / 26;
            res += ('a'+N%26);
            N = N/26;
        
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
        return 0;
    }