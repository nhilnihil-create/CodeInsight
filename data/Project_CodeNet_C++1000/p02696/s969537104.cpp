#include <bits/stdc++.h>
using namespace std;

void textIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}



int main()
{
    //textIO();
    fastIO();

    long long a, b , n;
    cin >> a >> b >> n;

    if(n < b){
        cout << ((a*n)/b) - (a*(n/b)) << '\n';
    }
    else{
        cout << ((a*(b-1))/b) - (a*((b-1)/b)) << '\n';
    }




    return 0;
}
