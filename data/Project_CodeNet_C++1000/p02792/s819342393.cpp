#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, digit = 0, num;
    cin >> n;
    num = n;


    long long int sum = 0;
    int ar[10][10];
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < 10; j++)
            ar[i][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        string s1;
        s1 = to_string(i);
        int len = s1.size()-1;

        int n1, n2;
        n1 = s1[0] - '0';
        n2 = s1[len] - '0';

        ar[n1][n2]++;
    }

    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            if(i != j)
                ar[i][j] = 2*ar[i][j];
            sum += ar[i][j]*ar[j][i];
            ar[i][j] = 0;
            ar[j][i] = 0;
        }
    }

    cout << sum;


    return 0;
}
