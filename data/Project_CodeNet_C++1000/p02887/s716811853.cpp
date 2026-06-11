#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;
typedef vector<int>vi;
typedef deque<int> di;
#define f(i, a, b) for(int i = a; i < b; i++)

int main () {
ll n;
string s;
cin >> n;
cin >> s;
ll sum = 1;
f(i, 0, n) {
if (i != n-1 && s[i] != s[i+1]) {
    sum +=1;

}

}
cout << sum;
return 0;
}
