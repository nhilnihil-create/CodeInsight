#include <iostream>
using namespace std;
#define MAX 2000

int c[MAX][MAX];
int lcs(string x, string y)
{
    int m = x.size();
    int n = y.size();
    int max1 = 0;
    x = ' '+x;
    y = ' '+y;
    for(int i=1; i<=m; i++)
        c[i][0] = 0;
    for(int j=1; j<=n; j++)
        c[0][j] = 0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i] == y[j])
                c[i][j] = c[i-1][j-1]+1;
            else if(c[i-1][j]>=c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
    }
}
int main()
{
    int n, t;
    string s1, s2;
    cin >> n;
    while(n--)
    {
        cin >> s1 >> s2;
        lcs(s1,s2);
        cout << c[s1.size()][s2.size()] << endl;
    }
    return 0;
}