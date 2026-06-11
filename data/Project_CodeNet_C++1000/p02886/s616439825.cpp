#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long int
#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec[i] = x;
    }
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
        sum += vec[i] * vec[j];
        }
    }
    
    cout << sum;
}







