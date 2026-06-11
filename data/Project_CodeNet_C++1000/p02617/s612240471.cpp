#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    long long int N;
    cin >> N;

    long long int n = N * (N+1) * (N+2) / 6;
	
  	long long int u, v;
    for(int i = 0; i < N - 1; i++) {
      	cin >> u >> v;
      	if ( u < v) n -= u * (N + 1 - v);
        if ( u > v) n -= v * (N + 1 - u);
    }

    cout << n;
}
