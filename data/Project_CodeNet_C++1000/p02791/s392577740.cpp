#include <bits/stdc++.h>
using namespace std;

#define SIZE_OF_ARRAY(array) sizeof(array)/sizeof(array[0])
typedef long long ll;

int main() {
    int N;
    cin >> N;
    int n = INT_MAX;
    int c = 0;
    int P;
    for(int i=0; i < N; i++){
        cin >> P;
        if(P <= n){
            n = P;
            c++;
        }
    }
    cout << c << endl;
}