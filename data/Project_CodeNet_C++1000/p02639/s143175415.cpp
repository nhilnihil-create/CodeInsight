#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;


typedef long long int ll;
typedef unsigned long long  ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef deque <int> di;
typedef deque <char> dc;
typedef vector<long long int> vll;

#define f(i, a, b) for (int i = a; i < b; i++)
#define f2(i, a, b) for (int i = a; i <=b; i++)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front;
int main() {
int x;
f(i, 0, 5) {
cin >> x;
if (x == 0) {
    cout << i+1;
}
}
return 0;
}
