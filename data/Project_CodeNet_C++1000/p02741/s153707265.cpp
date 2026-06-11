#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	int A[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int K;
    cin >> K;
    cout << A[K-1] << endl;
}