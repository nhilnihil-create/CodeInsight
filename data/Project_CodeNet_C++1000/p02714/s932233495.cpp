// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
using namespace std;
//
//int sumr[4001];
//int sumg[4001];
//int sumb[4001];
int iro[4001];
int main()
{
    
    int n;
    int sum = 0;


    string s;
    long long  sumr = 0;
        long long sumb = 0;
        long long sumg = 0;

    cin >> n;
    cin >> s;
   // sumr[0] = sumg[0] = sumb[0] = 0;
    for (int i = 0; i <= n-1; i++) {
        if (s[i] == 'R') {
            sumr++;
            iro[i] = 0;
        }
        else if (s[i] == 'G') {
            sumg++;
            iro[i] = 1;


        }
        else {
            sumb++;
            iro[i] = 2;
        }
    }
    long long cnt = 0;
    for (int k = 1; 2 * k + 1 <= n; k++) {
        for (int i = 0; 2 * k + i <= n-1; i++) {
            if (iro[i] != iro[i + k] && iro[i + k] != iro[i + 2 * k] && iro[i + 2 * k] != iro[i])cnt++;
        }
    }
    long long ans = sumb*sumg*sumr - cnt;

   // cout << sumb << endl;
   // cout << cnt << endl;
    cout << ans << endl;
    //for (int i = 0; i <= n-3; i++) {
    //    //for (int j = i + 1; j <= n - 2; j++) {
    //    //    for (int k = j + 1; k <= n - 1; k++) {
    //    //        if (j - i == k - j)continue;
    //    //        if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k])sum++;
    //    //    }
    //    //}
    //}

   // cout << sum << endl;

    return 0;
}

