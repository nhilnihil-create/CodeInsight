#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;
typedef vector<int>vi;
typedef deque<int> di;
#define f(i, a, b) for(int i = a; i < b; i++)

int main () {
int a;
int b;
cin >> a >> b;
b += b;
if (a - b >= 0) {

    cout << a-b;
}
else {

    cout << 0;
}
return 0;
}
