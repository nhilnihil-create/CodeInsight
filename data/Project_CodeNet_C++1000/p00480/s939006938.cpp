#include <iostream>

using namespace std;

typedef unsigned long long ui;

int main()
{
    ui nx[101];
    ui dp[101][21] = {{}};

    int n;
    cin >> n;
    for( int iii=0; iii<n; ++iii ) {
        cin >> nx[iii];
    }

    dp[0][nx[0]] = 1;

    for( int i=1; i<n-1; ++i ) {
        for( int j=0; j<=20; ++j ) {
            if ( dp[i-1][j] > 0 ) {
                ui const p = j + nx[i];
                if ( p >= 0 && p <= 20 )
                    dp[i][p] += dp[i-1][j];

                ui const m = j - nx[i];
                if ( m >= 0 && m <= 20 )
                    dp[i][m] += dp[i-1][j];
            }
        }
    }

/*
    for( int j=0; j<=20; ++j ) {
        for( int i=0; i<n-1; ++i ) {
            cout << dp[i][j] << ", ";
        }
        cout << endl;
    }
/**/

    cout << dp[n-2][nx[n-1]] << endl;
}