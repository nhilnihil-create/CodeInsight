#include <bits/stdc++.h>
using namespace std;

// const long long int MOD = 1000000007;
const int MOD = 1000000007;


int main() {
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
        Q[i]--;
    }
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        nums[i] = i;
    }
    int a=0,b=0,i=0;
    do {
        i++;
        if (nums == P) {
            a = i;
        }
        if (nums == Q) {
            b = i;
        }
        
    } while (next_permutation(nums.begin(), nums.end()));
    
    cout << abs(a-b) << endl;

}
