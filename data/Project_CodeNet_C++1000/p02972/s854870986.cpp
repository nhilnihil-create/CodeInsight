#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N;
   cin >> N;
   vector<int> a(N), ans(N);
   for(int i = 0; i < N; i++) {
       cin >> a[i];
   }
int sum = 0;
   for(int i = N; i >= 1; i--) {
       sum = 0;
       for(int j = i; j <= N; j += i) {
        sum += ans[j - 1];
       }
       if(sum % 2 == a[i - 1]) { ans[i - 1] = 0; }
       else ans[i - 1] = 1;
   }
    int m = 0;
    for(int i = 0; i < N; i++) {
        if(ans[i] == 1) m++; 
    }
    cout << m << endl;
    for(int i = 0; i < N; i++) {
        if(ans[i] == 1) cout << i + 1 << " ";
    }
    return 0;
}