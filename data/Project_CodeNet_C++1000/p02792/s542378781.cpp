#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<vector<long long> > c(10, vector<long long> (10, 0));

    for(long long i = 1; i <= n; i++){
        string s;
        s = to_string(i);
        long long up = s[0] - '0';
        long long low = s[s.size()-1] - '0';

        c[up][low]++;
    }

    long long count = 0;

    for(long long i = 0; i < 10; i++){
        for(long long j = 0; j < 10; j++){
            count += c[i][j]*c[j][i];
        }
    }

    cout << count << endl;
    return 0;
}