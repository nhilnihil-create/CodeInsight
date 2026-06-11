#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < 10;i++){
        for (int j = 0; j < 10;j++){
            for (int k = 0; k < 10;k++){
                int count = 0;
                for (int l = 0; l < n; l++)
                {
                    int c;
                    if (count == 0)
                        c = i;
                    else if (count == 1)
                        c = j;
                    else if (count == 2)
                        c = k;
                    else if(count == 3)
                        break;
                    if(s[l]-'0'==c)
                        count++;
                }
                if(count == 3)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}