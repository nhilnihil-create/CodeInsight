#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull; 
ull firstDigit(ull n) 
{ 
    while (n >= 10)  
        n /= 10; 
      
    return n; 
} 
  
int lastDigit(int n) 
{ 
    return (n % 10); 
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<ull>> arr = vector<vector<ull>>(10, vector<ull>(10, 0));

    for (int i = 1; i <= n; i ++) {
        arr[firstDigit(i)][lastDigit(i)] ++;
    }

    unsigned long long sum = 0;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            sum += arr[i + 1][j + 1] * arr[j + 1][i+1];
        }
    }

    cout << sum;

    return 0;
}