#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int sum = 0; char c[2000020];
int main()
{
    ios :: sync_with_stdio(false);
    cin >> c; for(int i = 0; c[i]; i++) sum += c[i] - '9';     
    puts(sum % 9 ? "No" : "Yes");
}