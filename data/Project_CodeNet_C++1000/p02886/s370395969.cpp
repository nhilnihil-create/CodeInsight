#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;
typedef vector<int>vi;
typedef deque<int> di;
#define f(i, a, b) for(int i = a; i < b; i++)

int main () {
int n;
cin >> n;
int x[n];
int sum = 0;
f(i, 0, n) {
cin >> x[i];

}
f(j , 0 , n) {

    f(k, 0, n) {
    if (j!=k) {
    sum+=(x[j]*x[k]);
    }
    }
}
cout << sum/2;
return 0;

}
