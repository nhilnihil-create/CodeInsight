// DivGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long n;
vector<long long> primes;
int powerCount = 0, moves = 0;

vector<long long> primeFactorize(long long n) {
    vector<long long> factorization;
    long long j = n;
    for (long long i = 2; i < (long long)sqrt(j); i++) {
        while (n % i == 0) {
            n /= i;
            factorization.push_back(i);
        }
    }
    if (n > 1) {
        factorization.push_back(n);
    }
    return factorization;
}

int numMoves(int count) {
    int i = 1;
    int moves = 0;
    while (count >= i) {
        moves++;
        count -= i;
        i++;
    }
    return moves;
}

int main()
{
    cin >> n;
    primes = primeFactorize(n);
    vector<int> counts;
    if (n > 1) {
        counts.push_back(1);
        for (int i = 1; i < (int)primes.size(); i++) {
            if (primes[i] == primes[i - 1]) {
                counts[counts.size() - 1]++;
            }
            else {
                counts.push_back(1);
            }
        }
    }
    for (int i = 0; i < (int)counts.size(); i++) {
        moves += numMoves(counts[i]);
    }
    cout << moves << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
