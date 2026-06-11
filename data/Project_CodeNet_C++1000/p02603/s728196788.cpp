#include <bits/stdc++.h>
#include <stdio.h>
typedef long long int LL;
#define fr(i,p,n) for(LL i=p;i<n;i++)
#define fr1(i,p,n) for(LL i=p;i>=n;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define precise cout << std::setprecision(10) << std::fixed;

using namespace std;
 
int main()
{
long long N, A[87], CurrentMoney = 1000;
 cin >> N;
 for (int i = 1; i <= N; i++) cin >> A[i];
 for (int i = 1; i <= N - 1; i++) {
 long long Stocks = 0;
 if (A[i] < A[i + 1]) Stocks = CurrentMoney / A[i];
 CurrentMoney += (A[i + 1] - A[i]) * Stocks;
 }
 cout << CurrentMoney << endl;
    return 0;
}