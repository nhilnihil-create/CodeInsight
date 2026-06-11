#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main ()
{

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define int ll
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    int cont[10][10];
    memset(cont, 0, sizeof(cont));

    int ans = 0;
    for (int i=1; i<=n; i++){
        string now = to_string(i);
        int first = now[0] - '0';
        int second = i%10;
        cont[first][second]++;
    }

    for (int i=1; i<=9; i++){
        for (int j=1; j<=9; j++){
            ans += cont[i][j]*cont[j][i];
        }
    }

    cout << ans << endl;
    cerr << "Sadat" << endl;

    return 0;

}
