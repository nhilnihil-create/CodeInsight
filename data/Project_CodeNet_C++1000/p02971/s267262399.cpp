// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<algorithm>
using namespace std;

int a[200005], sa[200005];
int main()
{
    int n;

    
    int max=0;
    int prev = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa[i] = a[i];
        //if (max <= a[i]) {
        //    prev = max;
        //    max = a[i];
        //}
    }
    sort(sa, sa + n);

    for (int i = 0; i < n; i++) {
        if (a[i] == sa[n-1]) {
            cout << sa[n-2]<< endl;
        }
        else {
            cout << sa[n-1] << endl;
        }
    }

    return 0;
}


