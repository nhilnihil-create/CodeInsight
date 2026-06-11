#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long long ull;
typedef long double ld;
#define in_arr(name,size) for(int i = 0;i<size;i++)\
cin >> name[i];
#define QUICK ios_base::sync_with_stdio(0);cout << fixed;
#define MOD 1e9+7

int main(){
    QUICK

    int maks = 0;
    int a,b;
    cin >> a >> b;
    vector<int>num(b);
    for(int i = 0;i<b;i++)
        cin >> num[i];
    sort(num.begin(),num.end());

for(int i = 0;i<b-1;i++)
{
    maks = max(maks,num[i+1]-num[i]);
}

    maks = max(maks, a-num[b-1]+num[0]);
    cout << a-maks;

   return 0;
}
