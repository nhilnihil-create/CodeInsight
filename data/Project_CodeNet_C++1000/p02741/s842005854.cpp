
// Problem : A - Kth Term
// Contest : AtCoder - Panasonic Programming Contest 2020
// URL : https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb "lower_bound"
#define ub "upper_bound"
#define bs "binary_search"

int dif(int a,int b){if(a > b)return a - b;else return b - a;}
int min(int a,int b){if(a > b)return b;else return a;}
int max(int a,int b){if(a > b)return a;else return b;}
int gcd(int a, int b){if(b == 0)return a;return gcd(b, a%b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int arr[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int n;
    cin>>n;
    cout<<arr[n - 1];
	return 0;
}
