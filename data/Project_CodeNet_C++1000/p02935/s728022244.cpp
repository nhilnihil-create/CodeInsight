// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    //int a[55];
    vector<int> v;
    int v1;
    double max =0;
    cin >> n;
    vector<int >a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double ans = a[0];
    for (int i = 1; i < n; i++) {
        ans += a[i];
        ans /= 2;
    }
    //for (int i = 1; i <= n; i++) {
    //    v.push_back(i);
    //}

    //do {
    //    double sum = a[v[0]];
    //    for (int i = 1; i < n; i++) {
    //        sum += a[v[i]];
    //        sum /= 2;

    //        if (i == n - 1) {
    //            if (max < sum)max = sum;

    //            
    //        }
    //    }
    //} while (next_permutation(v.begin(), v.end()));
    printf("%.10f", ans);
}

