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
    string s;
    cin >> s;
    int cnt = 1;
    for(int i = 0; i < n - 1; i++){
        if(s[i] != s[i + 1])
            cnt++;
    }
    cout << cnt;
}







