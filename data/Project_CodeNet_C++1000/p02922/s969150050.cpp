#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int A, B; cin >> A >> B;
 int ans = 0;
 int o = 1;
 while (o < B) {
 o--;
 o += A;
 ans++;
 }
cout << ans;
    return 0;

}
