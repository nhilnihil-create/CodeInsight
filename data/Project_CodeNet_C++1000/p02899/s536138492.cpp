#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long int N;
    cin >> N;
 
    long int arr[N+1];
    long int solved[N+1];
 
    for(long int n=1; n<=N; n++)
    {
        cin >> arr[n];
 
        solved[arr[n]] = n;
    }
 
    for(long int n=1; n<=N; n++)
    {
        cout << solved[n] << " ";
    }
 
    return 0;
}