#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

typedef unsigned long long int ull;
typedef long long int ll;

#define deb(x) cout << "Value - " << x << "\n"; 

using namespace std;

// Class Starts Here



// Class Ends Here

// Functions Starts Here

void prime()
{
    
}

// Functions Ends Here

int main()
{
    // *********************
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // *********************
    
    // Driver Function Starts Here

    ll arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    vector<ll> vec;
    for (int i=0; i<2; i++)
    {
        for (int j=2; j<4; j++)
        vec.push_back(arr[i]*arr[j]);
    }
    cout << *max_element(vec.begin(), vec.end()) << "\n";

    // Driver Function Ends Here
    return 0;
}