#include <iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rpt(i,x) for (int i = 0; i < x; i++)
#define fti(i,f,t) for (int i = f; i <= t; i++)
#define fte(i,f,t) for (int i = f; i < t; i++)
#define rptws(i,x,s) for (int i = 0; i < x; i += s)
#define llrpt(i,x) for (long long i = 0; i < x; i++)
#define llfti(i,f,t) for (long long i = f; i <= t; i++)
#define llfte(i,f,t) for (long long i = f; i < t; i++)


int main () {
    int n;
    cin>>n;

    int arr[n];
    int cnt = 0;
    rpt(i, n) {
        cin>>arr[i];
        if (arr[i] % 2 != 0 && (i+1) % 2 != 0) cnt++;
    }

    cout<<cnt;
    return 0;
}