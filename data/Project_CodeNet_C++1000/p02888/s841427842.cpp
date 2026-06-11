// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int kazu[1005];
    int ans = 0;
    cin >> n;
    int ruiseki[1005];
    vector<int>a;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        a.push_back(l);
        
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size() - 2; i++) {
        for (int j = i+1; j < a.size() - 1; j++) {
            for (int k = j+1; k < a.size(); k++) {
                if (a[i] + a[j] > a[k]) {
                    ans++;
                }
                else {
                    
                }
            }
        }
    }

    cout << ans << endl;
}

