#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int table[64][100000];
int b[64];
int Abit[64][100000];
int shift[64];
int dim;


void dump(const vector<int>& look, const int N) {
    for (int i=0; i<look.size(); i++) {
        for (int j=0; j<N; j++) {
            cerr << table[i][j] << " ";
        }
        cerr << endl;
    }
}
int main() {
    int N;
    cin >> N;
    long long A[100000];
    for (int i=0; i<N; i++) cin >> A[i];

    long long allxor = 0;
    for (int i=0; i<N; i++) allxor ^= A[i];

    vector<int> look;

    {
        long long i = allxor;
        for (int step=0; step<64; step++, i/=2) {
            if (i%2 == 0) {
                look.push_back(step);
            }
        }
    }
    reverse(look.begin(), look.end());

/*
    for (auto a : look) {
        cerr << a << " ";
    } cerr << endl;
*/

    for (int i=0; i<N; i++) {
        long long x = A[i];
        int step = 0;
        while (x > 0) {
            if (x % 2 == 1) {
                Abit[step][i] = 1;
            }
            x /= 2;
            step++;
        }
    }
    
    {
        int dim = 0;
        for (int a: look) {
            for (int i=0; i<N; i++) table[dim][i] = Abit[a][i];
            b[dim] = 1;
            dim++;
        }
    }

    
    long long left = 0;
    int rank = 0;
    for (int level=0; level<look.size(); level++) {
        int idx = -1;
        for (int i=rank; i<N; i++) {
            if (table[level][i] == 1) {
                idx = i;
                break;
            }
        }
        if (idx == -1) { //ill
            if (b[level] == 0) {
                left |= 1LL << look[level];
            }
            continue;
        }
        // swap
        for (int i=0; i<look.size(); i++) {
            int tmp = table[i][rank];
            table[i][rank] = table[i][idx];
            table[i][idx] = tmp;
        }
        for (int i=0; i<look.size(); i++) {
            if (i == level) continue;
            if (table[i][rank] == 0) continue;
            for (int j=0; j<=N; j++) {
                table[i][j] ^= table[level][j];
            }
            b[i] ^= b[level];
        }
        left |= 1LL << look[level];
        rank++;

        //dump(look, N);
    }
    cout << left + (allxor ^ left) << endl;    
    return 0;
}

